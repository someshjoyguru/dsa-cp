#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    string a, b;
    cin>>a>>b;
    vector<vector<ll>> dp(a.size()+1,vector<ll>(b.size()+1,0));
    for (ll i=0; i<=a.size(); i++)dp[i][0]=i;
    for (ll i=0; i<=b.size(); i++)dp[0][i]=i;
    // if (a[0]!=b[0])dp[0][0]=1;
    for (ll i=1; i<=a.size(); i++){
        for (ll j=1; j<=b.size(); j++){
            // if (s[0]dp[1][1])
            dp[i][j]=min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+(a[i-1]!=b[j-1])});
        }
    }
    // for (int i=0; i<a.size(); i++){
    //     for (int j=0; j<b.size(); j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[a.size()][b.size()];
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