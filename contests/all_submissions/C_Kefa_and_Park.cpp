#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dfs(int node, int parent, int temp, vector<vector <int>>& adj,vector<int>& v,int m){
    if (v[node])temp++;
    else temp=0;
    if (temp>m) return 0;
    if (adj[node].size()==1 && adj[node][0]==parent) return 1;
    int y=0;
    for (int ch : adj[node]){
        if (ch!=parent)y+=dfs(ch,node,temp,adj,v,m);
    }
    return y;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<int> v(n+1,0);
    vector<vector <int>> adj(n+1);
    for (int i=1; i<=n; i++)cin>>v[i];
    for (int i=1; i<n; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<dfs(1,-1,0,adj,v,m);
}

int main(){
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}