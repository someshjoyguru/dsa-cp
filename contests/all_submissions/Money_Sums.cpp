#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    ll sum=0;
    for (ll i=0; i<n; i++){
        cin>>v[i];
        sum+=v[i];
    }
    vector<ll> dp(sum+1,0);
    dp[0]=1;
    for (ll i=0; i<n; i++){
        ll coin=v[i];
        for (ll j=sum; j>=1;j--){
            if (j-coin>=0 && dp[j-coin])dp[j]=1;
        }
    }
    cout<<accumulate(dp.begin()+1,dp.end(),0)<<endl;
    for (ll i=1; i<=sum; i++)if (dp[i])cout<<i<<" ";
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