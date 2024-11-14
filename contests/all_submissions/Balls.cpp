#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}

void solve() {
    ll N, K;
    cin >> N >> K;
    
    vector<ll> elasticities(K);
    for (int i = 0; i < K; ++i) {
        cin >> elasticities[i];
    }

    ll result = 0;
    int subset_count = 1 << K;
    for (int mask = 1; mask < subset_count; ++mask) {
        ll subset_lcm = 1;
        int bits_set = 0;

        for (int i = 0; i < K; ++i) {
            if (mask & (1 << i)) {
                subset_lcm = lcm(subset_lcm, elasticities[i]);
                bits_set++;
                if (subset_lcm > N) break;
            }
        }

        if (subset_lcm <= N) {
            if (bits_set % 2 == 1) {
                result += N / subset_lcm;
            } else {
                result -= N / subset_lcm;
            }
        }
    }

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}
