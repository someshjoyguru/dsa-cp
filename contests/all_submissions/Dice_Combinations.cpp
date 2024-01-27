#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll mod = 1e9+7;

void solve(){
    ll n; cin>>n;
    vector<ll> dp(n+1,0);
    //dp[i]->no. of times the dice will be thrown to reach i
    dp[0]=1;
    for (ll i=1; i<=n; i++){
        for (ll j=1; j<=6; j++){
            if (i-j>=0)dp[i]+=dp[i-j];
            dp[i]%=mod;
        }
    }
    cout<<dp[n];
}

void solve2(){
    ll n; cin>>n;
    vector<ll> dp(n+1,0);
    //dp[i]->no. of times the dice will be thrown to reach from i to n
    dp[n]=1;
    for (ll i=n-1; i>=0; i--){
        for (ll j=1; j<=6; j++){
            if (i+j<=n)dp[i]+=dp[i+j];
            dp[i]%=mod;
        }
    }
    cout<<dp[0];
}

int main(){
    fastio()
    ll t=1;
    // cin >> t;
    while(t--){
        solve2();
    }
    return 0;
}