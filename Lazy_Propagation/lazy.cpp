#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vl;

class SegmentTree {
    vl tree, lazy;
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

    void propagate(ll node, ll l, ll r) {
        if (lazy[node] != 0) {
            tree[node] += (r - l + 1) * lazy[node];
            if (l != r) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    ll query(ll ql, ll qr, ll node, ll l, ll r) {
        propagate(node, l, r);
        if (ql > r || qr < l) return 0;
        if (ql <= l && qr >= r) return tree[node];
        ll mid = l + (r - l) / 2;
        ll left = query(ql, qr, 2 * node + 1, l, mid);
        ll right = query(ql, qr, 2 * node + 2, mid + 1, r);
        return left + right;
    }

    void updateRangeUtil(ll ul, ll ur, ll diff, ll node, ll l, ll r) {
        propagate(node, l, r);
        if (ul > r || ur < l) return;
        if (ul <= l && ur >= r) {
            tree[node] += (r - l + 1) * diff;
            if (l != r) {
                lazy[2 * node + 1] += diff;
                lazy[2 * node + 2] += diff;
            }
            return;
        }
        ll mid = l + (r - l) / 2;
        updateRangeUtil(ul, ur, diff, 2 * node + 1, l, mid);
        updateRangeUtil(ul, ur, diff, 2 * node + 2, mid + 1, r);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

public:
    SegmentTree(const vl &arr) {
        n = arr.size();
        ll height = ceil(log2(n));
        ll treeSize = 2 * pow(2, height) - 1;
        tree.resize(treeSize, 0);
        lazy.resize(treeSize, 0);
        buildTree(arr, 0, 0, n - 1);
    }

    ll query(ll l, ll r) {
        if (l < 0 || r >= n || l > r) {
            cout << "Invalid query range!" << endl;
            return -1;
        }
        return query(l, r, 0, 0, n - 1);
    }

    void updateRange(ll l, ll r, ll value) {
        if (l < 0 || r >= n || l > r) {
            cout << "Invalid update range!" << endl;
            return;
        }
        updateRangeUtil(l, r, value, 0, 0, n - 1);
    }
};

int main() {
    vl arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    SegmentTree stree(arr);

    cout << "Sum of elements in range [1, 5]: " << stree.query(1, 5) << endl;
    cout << endl;

    stree.updateRange(1, 3, 10);
    cout << "Sum of elements in range [1, 5] after updating [1, 3] by 10: " << stree.query(1, 5) << endl;

    return 0;
}