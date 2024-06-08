#include "bits/stdc++.h"
using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;
typedef vector<long long> vl;
typedef vector<vl> vll;

vll multiply(vll &A, vll &B) {
    vll C(2, vl(2));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] % MOD) % MOD;
    return C;
}

vll matPow(vll &a, int n) {
    vll res = {{1, 0}, {0, 1}};
    while (n) {
        if (n & 1)
            res = multiply(res, a);
        a = multiply(a, a);
        n /= 2;
    }
    return res;
}

int fib(int n) {
    if (n <= 1) return n;
    vll T = {{1, 1}, {1, 0}};
    T = matPow(T, n - 1);
    return T[0][0];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "The " << n << "th Fibonacci number is: " << fib(n) << endl;
    return 0;
}
