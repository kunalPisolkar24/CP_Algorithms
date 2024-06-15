#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while(b){
        a %= b;
        swap(a, b);
    }
    return a;
}


ll lcm (ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ll num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    ll resultLCM = lcm(num1, num2);
    cout << "LCM : " << resultLCM << endl;
    return 0;
}