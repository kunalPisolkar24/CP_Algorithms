#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;


ll ternarySearch(vl arr, ll x) {
    ll low = 0, high = arr.size() - 1;
    while(low <= high) {
        ll mid1 = low + (high - low) / 3;
        ll mid2 = high - (high - low) / 3;

        if(arr[mid1] == x) return mid1;
        else if(arr[mid2] == x) return mid2;
        else if (x < arr[mid1]) high = mid1 - 1;
        else if (x > arr[mid2]) low = mid2 + 1;
        else {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }
    return -1;
}


int main() {
    vl arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    ll x = 23;
    ll index = ternarySearch(arr, x);

    if(index == -1) cout << "Element not found";
    else cout << "Element found at index: " << index;
    cout << endl;
    return 0;
}