#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 998244353;
ll num=0;
ll den=0;


void sf(ll &n, ll &d) {
    ll cd = __gcd(n, d);
    n /= cd;
    d /= cd;
}

ll modInverse(ll a, ll m) {
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;

        t = m;

        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}


void fp(ll k, ll n) {
   
        vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, 0));

        
        dp[0][0] = 1;

        
        for (ll i = 1; i <= k; ++i) {
            for (ll j = 1; j <= n; ++j) {
                for (ll x = 1; x <= 6; ++x) {
                    if (j - x >= 0) {
                        dp[i][j] += dp[i - 1][j - x];
                    }
                }
            }
        }

    ll p=pow(6,k-1);
    for (ll r=1; r<=k; r++){
        ll total = 6;
        for (ll i = 1; i < r; ++i) {
            total *= 6;
        }
        
        num+=dp[r][n]*p;
        den+=total*p;
        p/=6;
    }

    return;

}

void solve(){
    ll n, k;
    cin>>n>>k;
    fp(k, n);
    // den=den*k;
    sf(num, den);
    // cout<<num<<" "<<den<<endl;
    ll inverseq = modInverse(den, MOD);
    ll result = (num * inverseq) % MOD;
    cout<<result;
}

int main(){
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}