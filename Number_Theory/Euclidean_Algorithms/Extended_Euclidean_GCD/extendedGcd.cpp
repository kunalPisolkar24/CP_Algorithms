#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

// Structure to store the GCD and coefficients (x, y)
struct GCDData {
    ll gcd;
    ll x;
    ll y;
};

// Extended Euclidean Algorithm
GCDData extendedGCD(ll a, ll b) {
    if (b == 0) {
        return {a, 1, 0}; 
    }

    GCDData temp = extendedGCD(b, a % b);
    ll gcd = temp.gcd;
    ll x = temp.y;
    ll y = temp.x - (a / b) * temp.y;

    return {gcd, x, y}; 
}

int main() {
    ll num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    GCDData result = extendedGCD(num1, num2);

    cout << "GCD: " << result.gcd << endl;
    cout << "Coefficients (x, y): (" << result.x << ", " << result.y << ")" << endl;

    // Verify the result (Bézout's identity)
    cout << "Verification: " << num1 * result.x + num2 * result.y << " (should be equal to GCD)" << endl;

    return 0;
}