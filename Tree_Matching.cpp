#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll num = 2e5+10;
vector<vector<ll>> adj(num);
vector<vector<ll>> dp(num,vector<ll>(2,0));

void dfs(ll node, ll parent){
    for (auto child : adj[node])
        if (child!=parent)dfs(child, node);
    
    for (auto child: adj[node]){
        if (child!=parent)
            dp[node][0]+=max(dp[child][0],dp[child][1]);
    }

    for (auto child: adj[node])
        if (child!=parent)
            dp[node][1] = max(dp[node][1], dp[child][0] + 1 + dp[node][0] - max(dp[child][0], dp[child][1]));
    
}

void solve(){
    ll n; cin>>n;
    for (ll i = 0; i < n-1; i++){
        ll u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    cout<<max(dp[1][0],dp[1][1])<<endl;
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}