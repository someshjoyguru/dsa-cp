#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vll vector<ll>
#define in(n) ll n; cin >> n;
#define vin(v, n) vll (v)(n); for (ll i = 0; i < n; i++) cin >> (v)[i];

const int MOD = 1e9 + 7;
const int MAX_N = 101;
const int MAX_K = 100010;

ll dp[MAX_N][MAX_K];

ll ff(int n, int k, vll& a) {
    // Initialize the dp array
    memset(dp, 0, sizeof(dp));
    dp[n][0] = 1;  // Base case: one way to achieve sum 0 when there are no elements left

    for (int id = n - 1; id >= 0; id--) {
        vector<ll> prefix_sum(k + 1, 0);
        
        // Build prefix sums for dp[id+1]
        prefix_sum[0] = dp[id + 1][0];
        for (int x = 1; x <= k; x++) {
            prefix_sum[x] = (prefix_sum[x - 1] + dp[id + 1][x]) % MOD;
        }

        // Calculate dp[id][left] using prefix sums
        for (int left = 0; left <= k; left++) {
            if (left - a[id] - 1 >= 0)
                dp[id][left] = (prefix_sum[left] - prefix_sum[left - a[id] - 1] + MOD) % MOD;
            else
                dp[id][left] = prefix_sum[left];
        }
    }

    return dp[0][k];
}

void solve() {
    in(n); in(k);
    vin(a, n);

    cout << ff(n, k, a) << endl;
}

int main() {
    fast;
    int t = 1;
    while (t--) solve();
}
