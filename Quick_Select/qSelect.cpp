#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

ll partition(vl &arr, ll low, ll high) {
    ll pivot = arr[high];
    ll i = low - 1;
    
    for (ll j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

ll quickSelect(vl &arr, ll low, ll high, ll k) {
    if (low <= high) {
        ll pi = partition(arr, low, high);
        
        if (pi == k - 1) {
            return arr[pi];
        } else if (pi > k - 1) {
            return quickSelect(arr, low, pi - 1, k);
        } else {
            return quickSelect(arr, pi + 1, high, k);
        }
    }
    return -1;
}

int main() {
    vl arr = {10, 7, 8, 9, 1, 5};
    ll n = arr.size();

    cout << "Input Array: \n";
    for (ll i : arr) {
        cout << i << " ";
    }
    cout << "\n";

    ll k = 4; // Find the 4th smallest element
    cout << k << "th Smallest Element: " << quickSelect(arr, 0, n - 1, k) << "\n";

    k = n - 3; // Find the 4th largest element
    cout << "4th Largest Element: " << quickSelect(arr, 0, n - 1, k) << "\n";

    return 0;
}