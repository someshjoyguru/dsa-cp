#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll mod = 1e9+7;

void solve(){
    ll n,x;
    cin>>n>>x;
    vector<ll> c(n);
    for (ll i=0; i<n; i++)cin>>c[i];
    vector<ll> dp(x+1);
    // dp[i] -> no. of ways/coin combinations to get the sum of i
    dp[0]=1;
    for (ll i=1; i<=x; i++){
        for (ll j=0; j<n; j++){
            if (i-c[j]>=0){
                dp[i]=(dp[i]+dp[i-c[j]])%mod;
            }
        }
    }
    cout<<dp[x];
}

int main(){
    fastio()
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}