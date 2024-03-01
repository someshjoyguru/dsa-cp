#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll num = 2e5+10;
vector<vector<ll>> adj(num);
vector<ll> sub(num,1);

void dfs(ll node, ll parent){
    for (auto child : adj[node]){
        if (child!=parent)dfs(child, node);
    }

    for (auto child : adj[node]){
        if (child!=parent)sub[node]+=sub[child];
    }
}

void solve(){
    ll n; cin>>n;
    vector<ll> v(n);
    for (ll i=0; i<n-1; i++)cin>>v[i];
    for (ll i=0; i<n-1; i++){
        adj[v[i]].push_back(i+2);
        adj[i+2].push_back(v[i]);
    }
    dfs(1,-1);
    for (ll i=1; i<=n; i++)cout<<sub[i]-1<<" ";
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}