#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n,x;
    cin>>n>>x;
    vector<ll> c(n);
    for (ll i=0; i<n; i++)cin>>c[i];
    vector<ll> dp(x+1,1e9);
    dp[0]=0;
    // dp[i] -> min coins to generate a sum of i
    for (ll i=1; i<=x; i++){
        for (ll j=0; j<n; j++){
            if (i-c[j]>=0) dp[i]=min(dp[i],dp[i-c[j]]+1);
        }
    }
    if (dp[x]==1e9)cout<<-1;
    else cout<<dp[x];
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