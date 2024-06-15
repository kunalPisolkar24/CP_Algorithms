#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

vl calculateSPF(ll limit) {
    vl spf(limit + 1);
    for (ll i = 0; i <= limit; i++) {
        spf[i] = i; 
    }

    for (ll i = 2; i * i <= limit; i++) {
        if (spf[i] == i) { 
            for (ll j = i * i; j <= limit; j += i) {
                if (spf[j] == j) { 
                    spf[j] = i;
                }
            }
        }
    }
    return spf;
}

// Function to compute prime factors using the SPF array
map<ll, ll> primeFactorization(ll n, const vl& spf) {
    map<ll, ll> factors;
    while (n != 1) {
        factors[spf[n]]++;
        n /= spf[n];
    }
    return factors;
}

void printPrimeFactors(const map<long long, ll>& factors) {
    bool firstFactor = true;
    for (auto const& [prime, exponent] : factors) {
        if (!firstFactor) {
            cout << " x ";
        }
        cout << prime; 
        if (exponent > 1) {  
            cout << "^" << exponent;
        }
        firstFactor = false;
    }
    if (factors.empty()) {
        cout << "1"; 
    }
    cout << endl;
}

int main() {
    ll limit = 50000; 
    vl spf = calculateSPF(limit); 

    ll num;
    cout << "Enter a number: ";
    cin >> num;

    map<ll, ll> primeFactors = primeFactorization(num, spf);
    cout << "Prime factorization: ";
    printPrimeFactors(primeFactors);

    return 0;
}