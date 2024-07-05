#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

ll binomialCoeff(ll n, ll k) {
    vvl C(n + 1, vl(k + 1));    

    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i) C[i][j] = 1;
            else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}

int main() {
    ll n, k;
    cout << "Enter the value of n and k: ";
    cin >> n >> k;
    cout << "C(" << n << ", " << k << ") = " << binomialCoeff(n, k) << endl;
    return 0;
}
