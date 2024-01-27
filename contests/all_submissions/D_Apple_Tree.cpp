#include <bits/stdc++.h>
using namespace std;
#define ll long long


void dfs3(ll node, ll parent,vector<ll>& v, vector<vector<ll>>& adj){
    for (ll c: adj[node]){
        // cout<<"c : "<<c<<endl;
        // cout<<"x going : "<<x<<endl;

        if (c!=parent){
            if (adj[c].size()==1)v[c]++;
            else dfs3(c,node,v,adj);
            v[node]+=v[c];
        }

        // if (adj[c].size()==1 && c!=0) v[c]++;
        // else {
        //     if (c!=parent)dfs3(c, node, v, adj);
        // }
        // // cout<<"x ret : "<<x<<endl;
        // v[node]+=v[c];
    }
}

void dfs2(ll node, ll parent,ll& x, vector<vector<ll>>& adj){
    for (ll c: adj[node]){
        // cout<<"c : "<<c<<endl;
        // cout<<"x going : "<<x<<endl;
        if (adj[c].size()==1)x++;
        else {
            if (c!=parent)dfs2(c, node, x, adj);
        }
        // cout<<"x ret : "<<x<<endl;
    }
}
// ll func(ll n,ll p,vector<vector<ll>>& adj){
//     ll x=0;
//     dfs2(n, p,x,adj);
//     return x;
// }
void dfs(ll node, ll parent, vector<ll>& p, vector<vector<ll>>& adj){
    p[node]=parent;
    for (ll i : adj[node]){
        if (i!=p[node]){
            dfs(i, node, p, adj);
        }
    }
}

void solve(){
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n+1);
    vector<ll> par(n+1);
    par[1]=0;
    par[0]=0;
    for (ll j=0; j<n-1; j++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        // for (ll i=0; i<n+1; i++){
        //     cout<<i<<" : ";
        //     for (ll c : adj[i]){
        //         cout<<c<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    adj[1].push_back(0);
    vector<ll> count(n+1);
    dfs(1,0,par,adj);
    // for (ll i: par){
    //     cout<<i<<" ";

    // }
    // for (ll i=0; i<n+1; i++){
    //     cout<<i<<" : ";
    //     for (ll c : adj[i]){
    //         cout<<c<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    vector<ll> v(n+1,0);
    dfs3(1,0,v,adj);
    for (ll i: v) cout<<i<<" ";
    cout<<endl;
    cin>>n;
    for (ll i=0; i<n; i++){
        ll x,y;
        cin>>x>>y;
        // ll k=0,m=0;
        // dfs2(x,par[x],k,adj);
        // dfs2(y,par[y],m,adj);
        // if (k==0)k++;
        // if (m==0)m++;
        // cout<<k<<" "<<m<<endl;
        cout<<v[x]*v[y]<<endl;
    }
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}