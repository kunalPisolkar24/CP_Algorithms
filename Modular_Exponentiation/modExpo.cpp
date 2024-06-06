#include "bits/stdc++.h"
using namespace std;

#define Mod 1000000007
typedef long long ll;

ll pow(ll a, ll b) {
    ll res = 1;
    a %= Mod;  
    while (b) {
        if (b & 1) 
            res = (res * a) % Mod;  
        a = (a * a) % Mod;        
        b >>= 1;                    
    }
    return res;
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << pow(a, b) << endl;
}