#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

ll catalanDP(ll n) {
    vl C(n + 1, 0);
    C[0] = 1;

    for (ll i = 1; i <= n; i++) 
        for(ll j = 0; j < i; ++j) 
            C[i] += C[j] * C[i - j - 1];
    return C[n];
}

int main() {
    ll n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "C(" << n << ") = " << catalanDP(n) << endl;
    return 0;
}