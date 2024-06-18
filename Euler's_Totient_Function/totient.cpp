#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

vl eulerTotientSieve(ll n) {
    vl phi(n + 1);
    iota(phi.begin(), phi.end(), 0);

    for(ll p = 2; p <= n; p++) 
        if(phi[p] == p) 
            for(ll k = p; k <= n; k += p) phi[k] -= phi[k] / p;

    return phi;
}

int main() {
    ll n;
    cout << "Enter the limit (n): ";
    cin >> n;

    vl totient = eulerTotientSieve(n);

    for(ll i = 1; i <= n; i++) 
        cout << "phi(" << i << ") = " << totient[i] << endl;

    return 0;

}