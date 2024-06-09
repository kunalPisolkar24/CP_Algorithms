#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

vector<bool> sieve(ll n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false; 

    for (ll i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return is_prime;
}

int main() {
    ll n;
    cout << "Enter the limit n: ";
    cin >> n;

    vector<bool> primes = sieve(n);

    cout << "Prime numbers up to " << n << " are: ";
    for (ll i = 2; i <= n; i++) {
        if (primes[i]) cout << i << " ";
    }

    cout << endl;

    return 0;
}
