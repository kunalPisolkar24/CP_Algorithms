#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

// Recursive function to calculate GCD using Euclidean Algorithm
ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b); 
}

// Iterative function to calculate GCD using Euclidean Algorithm
ll gcdIterative(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ll num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    ll resultRecursive = gcd(num1, num2);
    ll resultIterative = gcdIterative(num1, num2);

    cout << "GCD (Recursive): " << resultRecursive << endl;
    cout << "GCD (Iterative): " << resultIterative << endl;

    return 0;
}