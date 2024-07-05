#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

// Function to compute the prime factors and their exponents
map<ll, int> computePrimeFactors(ll n) {
    map<ll, int> factors; 

    while (n % 2 == 0) {
        factors[2]++;
        n /= 2;
    }

    for (ll i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }

    if (n > 1) factors[n]++; 

    return factors;
}

// Function to print the prime factorization 
void printPrimeFactors(const map<ll, int>& factors) {
    bool firstFactor = true;
    for (auto const& [prime, exponent] : factors) {
        if (!firstFactor) cout << " x ";
        cout << prime;

        if (exponent > 1) cout << "^" << exponent;
        firstFactor = false;
    }
    if (factors.empty())  cout << "1"; 
    cout << endl;
}

int main() {
    ll num;
    cout << "Enter a number: ";
    cin >> num;

    // Compute the prime factors
    map<ll, int> primeFactors = computePrimeFactors(num); 

    // Print the result
    cout << "Prime factorization: ";
    printPrimeFactors(primeFactors); 

    return 0;
}