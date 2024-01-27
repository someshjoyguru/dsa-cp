#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 998244353;

int modpow(int base, int exponent, int modulus) {
    int result = 1;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }

        base = (base * base) % modulus;
        exponent /= 2;
    }

    return result;
}

int main() {
    int k, n;
    cin >> k >> n;

    vector<int> binom(n + 1);
    binom[0] = 1;

    for (int i = 1; i <= n; ++i) {
        binom[i] = 1LL * binom[i - 1] * (n - i + 1) % MOD;
        binom[i] = 1LL * binom[i] * modpow(i, MOD - 2, MOD) % MOD;
    }

    int ans = 0;

    for (int i = 0; i < k; ++i) {
        ans += (i % 2 == 0 ? 1 : -1) * binom[n];
        ans %= MOD;
        n += 1;
    }

    if (ans < 0) {
        ans += MOD;
    }

    cout << ans << endl;

    return 0;
}