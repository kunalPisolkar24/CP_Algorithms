#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vl;

class SegmentTree {
    vl tree;
    ll n;

    void buildTree(const vl &arr, ll node, ll l, ll r) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        ll mid = l + (r - l) / 2;
        buildTree(arr, 2 * node + 1, l, mid);
        buildTree(arr, 2 * node + 2, mid + 1, r);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    ll query(ll ql, ll qr, ll node, ll l, ll r) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && qr >= r) return tree[node];
        ll mid = l + (r - l) / 2;
        ll left = query(ql, qr, 2 * node + 1, l, mid);
        ll right = query(ql, qr, 2 * node + 2, mid + 1, r);
        return left + right;
    }

    void updateValueUtil(ll index, ll diff, ll node, ll l, ll r) {
        if (index < l || index > r) return;
        tree[node] += diff;
        if (l != r) {
            ll mid = l + (r - l) / 2;
            updateValueUtil(index, diff, 2 * node + 1, l, mid);
            updateValueUtil(index, diff, 2 * node + 2, mid + 1, r);
        }
    }
public:
    SegmentTree(const vl &arr) {
        n = arr.size();
        ll height = ceil(log2(n));
        ll treeSize = 2 * pow(2, height) - 1;
        tree.resize(treeSize, 0);
        buildTree(arr, 0, 0, n - 1);
    }

    ll query(ll l, ll r) {
        if (l < 0 || r >= n || l > r) {
            cout << "Invalid query range!" << endl;
            return -1;
        }
        return query(l, r, 0, 0, n - 1);
    }

    void update(ll index, ll value) {
        if (index < 0 || index >= n) {
            cout << "Invalid index!" << endl;
            return;
        }
        ll diff = value - query(index, index);
        updateValueUtil(index, diff, 0, 0, n - 1);
    }
};

int main() {
    vl arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    SegmentTree stree(arr);

    cout << "Sum of elements in range [1, 5]: " << stree.query(1, 5) << endl;
    cout << endl;

    stree.update(3, 10);
    cout << "Sum of elements in range [1, 5]: " << stree.query(1, 5) << endl;

    return 0;
}

