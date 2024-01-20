#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll inf = 1e9+20;
const ll mod = 1e9+7;
void solve(){
    // input
    ll n; cin>>n;
    vector<vector<ll>> dp(n,vector<ll>(n,0));
    for (ll i=0; i<n; i++){
        string s; cin>>s;
        for (ll j=0; j<n; j++){
            if (s[j]=='*'){
                // v[i][j]=inf;
                dp[i][j]=inf;
            }
        }
    }

    // dp table
    //base case
    for (ll i=0; i<n; i++){
        if (dp[i][0]!=inf) dp[i][0]=1;
        else break;
    }

    for (ll i=0; i<n; i++){
        if (dp[0][i]!=inf) dp[0][i]=1;
        else break;
    }

    for (ll i=1; i<n; i++){
        for (ll j=1; j<n; j++){
            if (dp[i][j]==inf) continue;
            if (dp[i-1][j]!=inf)dp[i][j]+=dp[i-1][j];
            if (dp[i][j-1]!=inf)dp[i][j]+=dp[i][j-1];
            dp[i][j]%=mod;
        }
    }

    for (ll i=0; i<n; i++){
        for (ll j=0; j<n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    // if (dp[n-1][n-1]<inf) cout<<dp[n-1][n-1];
    // else cout<<0;
    cout<<dp[n-1][n-1];
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

// don't forget the edge cases 
// while filling base case 
// mod
// when no. of paths is 0