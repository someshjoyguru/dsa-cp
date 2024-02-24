#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll num = 1e5+5;
vector<vector<ll>> adj(num);
vector<vector<ll>> v(num,vector<ll>(2,0));
vector<vector<ll>> dp(num,vector<ll>(2,0));

void dfs(ll node, ll par){
    // base case done
    // go go go
    for (auto c : adj[node]){
        if (c==par)continue;
        dfs(c,node);
    }

    // recurrence
    // dp[i][0] = left- (left or right ka max)
    // dp[i][1] = right - (left or right ka max)
    for (auto c: adj[node]){
        if (c==par)continue;
        dp[node][0]+=max(abs(v[node][0]-v[c][0])+dp[c][0],abs(v[node][0]-v[c][1])+dp[c][1]);
        dp[node][1]+=max(abs(v[node][1]-v[c][0])+dp[c][0],abs(v[node][1]-v[c][1])+dp[c][1]);
    }
}

void solve(){
    ll n; cin>>n;
    for (ll i=1; i<=n; i++){
        adj[i].clear();
        dp[i][0]=0; dp[i][1]=0;
    }
    for (ll i=1; i<=n; i++){
        cin>>v[i][0]>>v[i][1];
    }
    for (ll i=1; i<=n-1; i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    cout<<max(dp[1][0],dp[1][1])<<endl;
}

int main(){
    fast;
    int t;
    cin >> t;
    while(t--)solve();
}