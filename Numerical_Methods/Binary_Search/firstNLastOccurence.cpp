#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

ll binarySearchFirstOccurrence(vl& arr, ll target) {
    ll left = 0;
    ll right = arr.size() - 1;
    ll result = -1;

    while (left <= right) {
        ll mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

ll binarySearchLastOccurrence(vl& arr, ll target) {
    ll left = 0;
    ll right = arr.size() - 1;
    ll result = -1;

    while (left <= right) {
        ll mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            left = mid + 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    vl arr = {1, 2, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ll target = 2;

    ll firstOccurrence = binarySearchFirstOccurrence(arr, target);
    ll lastOccurrence = binarySearchLastOccurrence(arr, target);

    if (firstOccurrence != -1) {
        cout << "First occurrence at index " << firstOccurrence << endl;
    } else {
        cout << "Element not found" << endl;
    }

    if (lastOccurrence != -1) {
        cout << "Last occurrence at index " << lastOccurrence << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
