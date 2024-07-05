#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<long long> vl;

ll partition(vl &arr, ll low, ll high) {
    ll pivot = arr[high];
    ll i = low - 1;
    for(ll j = low; j <= high - 1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vl &arr, ll low, ll high) {
    if(low < high) {
        ll pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() { 
    vl arr = {10, 7, 8, 9, 1, 5};

    cout << "Input Array: \n";
    for(ll i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: \n";
    for(ll i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}