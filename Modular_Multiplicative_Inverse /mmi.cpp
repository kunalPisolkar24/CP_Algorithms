#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

// Extended Euclidean Algorithm to find GCD and coefficients
pll extendedGCD(ll a, ll b) {
    if (b == 0) {
        return {1, 0}; 
    }

    pll temp = extendedGCD(b, a % b);
    ll x = temp.second;
    ll y = temp.first - (a / b) * temp.second;
    return {x, y};
}

// Function to calculate the modular multiplicative inverse
int modInverse(ll a, ll m) {
    pll result = extendedGCD(a, m);
    ll x = result.first;

    // If inverse doesn't exist
    if (x < 0) 
        x = (x % m + m) % m;

    return x;
}

int main() {
    ll a, m;

    cout << "Enter the number (a): ";
    cin >> a;
    cout << "Enter the modulo (m): ";
    cin >> m;

    ll inverse = modInverse(a, m);

    if (inverse != -1) {
        cout << "The multiplicative inverse of " << a << " modulo " << m << " is: " << inverse << endl;
    } else {
        cout << "Multiplicative inverse doesn't exist for " << a << " modulo " << m << endl;
    }

    return 0;
}