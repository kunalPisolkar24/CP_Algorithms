#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
// Function to generate prime numbers up to a given limit using Sieve of Eratosthenes
vl sieveOfEratosthenes(ll limit) {
    vector<bool> isPrime(limit + 1, true); 
    isPrime[0] = isPrime[1] = false; 

    for (ll i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (ll j = i * i; j <= limit; j += i) {
                isPrime[j] = false; 
            }
        }
    }

    vl primes;
    for (ll i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

// Function to compute prime factors and their exponents
map<ll, int> computePrimeFactors(ll n) {
    map<ll, int> factors;
    vl primes = sieveOfEratosthenes(sqrt(n)); // Precompute primes

    for (ll prime : primes) {
        while (n % prime == 0) {
            factors[prime]++;
            n /= prime;
        }
    }
    if (n > 1) factors[n]++; 
    return factors;
}

// Function to print the prime factorization
void printPrimeFactors(const map<ll, int>& factors) {
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
    ll num;
    cout << "Enter a number: ";
    cin >> num;

    map<ll, int> primeFactors = computePrimeFactors(num);
    cout << "Prime factorization: ";
    printPrimeFactors(primeFactors); 

    return 0;
}