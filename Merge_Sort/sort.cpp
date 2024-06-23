#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;


void merge(vl &arr, ll left, ll mid, ll right) {
    ll i = left;
    ll j = mid + 1;
    ll k = 0;

    vl temp;

    while(i <= mid and j <= right) {
        if(arr[i] <= arr[j]) 
            temp.push_back(arr[i++]);
        else 
            temp.push_back(arr[j++]);
    }

    while(i <= mid) 
        temp.push_back(arr[i++]);

    while(j <= right) 
        temp.push_back(arr[j++]);
    
    for(ll idx = left; idx <= right; idx++)
        arr[idx] = temp[k++];

    return;
}

void mergeSort(vl &arr, ll left, ll right) {
    if(left < right) {

        ll mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {

    vl arr = {12, 11, 13, 5, 6, 7};
    ll n = arr.size();

    mergeSort(arr, 0, n - 1);

    for(ll i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}