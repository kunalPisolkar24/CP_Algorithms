#include <iostream>

using namespace std;

typedef long long ll;

// Extended Euclidean Algorithm (modified to return GCDData structure)
struct GCDData {
    ll gcd;
    ll x;
    ll y;
};

GCDData extendedGCD(ll a, ll b) {
    if (b == 0) {
        return {a, 1, 0};
    }
    GCDData temp = extendedGCD(b, a % b);
    ll x = temp.y;
    ll y = temp.x - (a / b) * temp.y;
    return {temp.gcd, x, y};
}

// Function to find one solution for ax + by = c
pair<bool, GCDData> solveDiophantine(ll a, ll b, ll c) {
    GCDData gcdData = extendedGCD(a, b);
    ll gcd = gcdData.gcd;

    if (c % gcd != 0) {
        return {false, {gcd, 0, 0}}; // No solution if c is not divisible by gcd(a, b)
    }

    // Calculate a particular solution
    ll x0 = gcdData.x * (c / gcd);
    ll y0 = gcdData.y * (c / gcd);

    return {true, {gcd, x0, y0}};
}

int main() {
    ll a, b, c;

    cout << "Enter the coefficients a, b, and c (ax + by = c): ";
    cin >> a >> b >> c;

    auto [hasSolution, solution] = solveDiophantine(a, b, c);

    if (hasSolution) {
        cout << "One solution is: " << endl;
        cout << "x = " << solution.x << endl;
        cout << "y = " << solution.y << endl;
    } else {
        cout << "No solution exists for the given equation." << endl;
    }

    return 0;
}