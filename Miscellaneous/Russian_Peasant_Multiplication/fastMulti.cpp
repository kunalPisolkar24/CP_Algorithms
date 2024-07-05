#include <iostream>
using namespace std;
typedef long long ll;
#define MOD 1000000007

ll fastMultiply(ll a, ll b) {
    ll res = 0;
    while (b) {
        if (b & 1) 
            res = (res + a) % MOD; 
        a = (a << 1) % MOD;   
        b = b >> 1;  
    }
    return res;
}

int main() {
    ll num1, num2;
    cin >> num1 >> num2;
    ll product = fastMultiply(num1, num2);
    cout << product << endl;
    return 0;
}