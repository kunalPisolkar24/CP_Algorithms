#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;

pll extendedGCD(ll a, ll b) {
    if (b == 0) 
        return {1, 0};
    pll temp = extendedGCD(b, a % b);
    ll x = temp.second;
    ll y = temp.first - (a / b) * temp.second;
    return {x, y};
}

ll modInverse(ll a, ll m) {
    ll x = extendedGCD(a, m).first;
    return (x % m + m) % m;
}

ll chineseRemainder(vl &num, vl &rem) {
    ll prod = 1, res = 0, size = num.size(); 

    assert(size == rem.size());

    for (ll i = 0; i < size; i++) 
        prod *= num[i];

    for (ll i = 0; i < size; i++) {
        ll p = prod / num[i];
        res += rem[i] * modInverse(p, num[i]) * p;
    }
    return res % prod;
}

int main() {
    vl num = {3, 4, 5};
    vl rem = {2, 3, 1};

    for(ll i = 0; i < num.size(); i++) 
        for(ll j = i + 1; j < num.size(); j++) 
            assert(__gcd(num[i], num[j]) == 1);
    
    ll res = chineseRemainder(num, rem);

    cout << "The solution for the given system is: " << res << endl;

    return 0;
}