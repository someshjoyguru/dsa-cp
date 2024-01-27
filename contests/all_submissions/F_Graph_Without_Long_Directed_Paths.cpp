#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n=6;

bool dfs(int node,int pcolor,vector<int>& vis, vector<int>& col, vector<vector<int>>& adj){
    vis[node]=1;
    col[node]=pcolor;
    // cout<<"node : "<<node<<endl;
    // cout<<"col : "<<endl;
    // for (int i=1; i<=n; i++)cout<<col[i];
    // cout<<endl;
    // cout<<"vis : "<<endl;
    // for (int i=1; i<=n; i++)cout<<vis[i];
    // cout<<endl;
    // cout<<endl;
    int chcol= 1-pcolor;
    bool y=true;
    for (int ch: adj[node]){
        if ((vis[ch]==1) && (chcol=col[ch])) return false;
        if (vis[ch]==0){
            y&=dfs(ch,chcol,vis,col,adj);
        }
    }
    return y;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<pair<int,int>> ans;
    for (int i=0; i<m; i++){
        ll u,v;
        cin>>u>>v;
        ans.push_back({u,v});
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    // for (int i=1; i<=n; i++){
    //     cout<<i<<" ";
    //     for (int ch: adj[i]){
    //         cout<<ch<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<int> col(n+1,0);
    vector<int> vis(n+1,0);
    
    // applying 2 coloring strategy
    if (dfs(1,1,vis,col,adj)){
        cout<<"YES"<<endl;
        // for (int i=1; i<=n; i++)cout<<col[i];
        for (auto ch : ans){
            if (col[ch.first]){
                cout<<1;
            }else{
                cout<<0;
            }
        }
    }else{
        cout<<"N0";
    }
}

int main(){
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}