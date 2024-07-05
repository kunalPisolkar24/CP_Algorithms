#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

class FenwickTree {
private:
    vl tree;
    ll n;

    ll LSB(ll i) {
        return i & (-i);
    }

public:
    FenwickTree(ll size): n(size + 1) {
        tree.resize(n, 0);
    }

    void update(ll i, ll delta) {
        while(i < n) {
            tree[i] += delta;
            i += LSB(i);
        }
    }

    ll prefixSum(ll i) {
        ll sum = 0;
        while(i > 0) {
            sum += tree[i];
            i -= LSB(i);
        }
        return sum;
    }

    ll rangeSum(ll l, ll r) {
        return prefixSum(r) - prefixSum(l - 1);
    }

    void build(vl &arr) {
        for(ll i = 0; i < arr.size(); i++)
            update(i + 1, arr[i]);
    }
};

int main() {
    vl arr = {3, 2, -1, 6, 5, 4, -3, 3, 7, 2, 3};

    ll n = arr.size();

    FenwickTree ft(n);
    ft.build(arr);

    cout << "Sum of elements in range [1, 5]: " << ft.rangeSum(2, 6) << endl;

    ft.update(3, 5);

    cout << "Sum of elements in range [1, 5] after update: " << ft.rangeSum(2, 6) << endl;

    return 0;

}
