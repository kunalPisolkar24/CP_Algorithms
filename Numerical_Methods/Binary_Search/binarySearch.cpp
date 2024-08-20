#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

ll binarySearch(vl& arr, ll target) {
    ll left = 0;
    ll right = arr.size() - 1;

    while (left <= right) {
        ll mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

ll binarySearchRecursive(vl &arr,ll left,ll right,ll target) {
    if (left <= right) {
        ll mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            return binarySearchRecursive(arr, mid + 1, right, target);
        } else {
            return binarySearchRecursive(arr, left, mid - 1, target);
        }
    }

    return -1;
}

int main() {
    vl arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ll target = 11;

    ll result = binarySearchRecursive(arr, 0, arr.size() - 1, target);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
