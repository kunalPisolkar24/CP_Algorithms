#include "bits/stdc++.h"
using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;

ll addMod(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll subMod(ll a, ll b) {
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

ll mulMod(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll powMod(ll a, ll b) {
    ll res = 1;
    a %= MOD;  
    while (b) {
        if (b & 1) 
            res = (res * a) % MOD;  
        a = (a * a) % MOD;        
        b >>= 1;                    
    }
    return res;
}

ll divMod(ll a, ll b) {
    return ((a % MOD) * powMod(b, MOD - 2)) % MOD;
}

int main() {
    ll a, b;
    cout << "Enter two numbers (a, b): ";
    cin >> a >> b;

    cout << "Addition: " << addMod(a, b) << endl;
    cout << "Subtraction: " << subMod(a, b) << endl;
    cout << "Multiplication: " << mulMod(a, b) << endl;
    cout << "Power: " << powMod(a, b) << endl;
    cout << "Division: " << divMod(a, b) << endl;

}

