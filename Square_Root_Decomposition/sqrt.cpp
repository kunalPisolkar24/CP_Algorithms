#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

class SqrtDecomposition {
private:
    vl arr;
    vl blocks;
    ll block_size, n;
public:

    SqrtDecomposition(const vl& input) {
        arr = input;
        n = arr.size();
        block_size = static_cast<ll>(sqrt(n) + 1);
        blocks.resize((n + block_size - 1) / block_size);

        for(ll i = 0; i < n; i++)
            blocks[i / block_size] += arr[i];
    }

    void update(ll idx, ll val) {
        ll block_idx = idx / block_size;
        blocks[block_idx] -= arr[idx];
        blocks[block_idx] += val;
        arr[idx] = val;
    }

    ll query(ll l, ll r) {
        ll sum = 0;
        ll start_block = l / block_size;
        ll end_block = r / block_size;

        if(start_block == end_block) {
            for(ll i = l; i <= r; i++)
                sum += arr[i];
        }else {
            for(ll i = l; i < (start_block + 1) * block_size; i++)
                sum += arr[i];

            for(ll i = start_block + 1; i < end_block; i++)
                sum += blocks[i];

            for(ll i = end_block * block_size; i <= r; i++)
                sum += arr[i];
        }
       return sum;
    }
};

int main() {
    vl arr = {1, 5, 2, 4, 6, 1, 3, 5, 7, 10};
    SqrtDecomposition sqd(arr);

    cout << "Sum of elements in range [2, 7]: " << sqd.query(2, 7) << endl;

    sqd.update(4, 8); 

    cout << "Sum of elements in range [2, 7] after update: " << sqd.query(2, 7) << endl;

    return 0;
}
