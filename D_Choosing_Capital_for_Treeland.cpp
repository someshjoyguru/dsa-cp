#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int num =2e5+10;
vector<vector<ll>> adj(num);
vector<vector<ll>> adj1(num);
int cost=0;

void dfs(ll node, ll par){
    if ((adj1[node].size())==1 && adj1[node][0]==par){
        return;
    }
    for (ll child: adj1[node]){
        if (child==par)continue;
        dfs(child,node);
    }
    for (ll child : adj1[node]){
        if (child==par)continue;
        ll flag1=0,flag2=0;
        for (ll child1 : adj[node]){
            if (child1==child){
                flag1=1;
                break;
            }
        }
        for (ll child1 : adj[node]){
            if (child1==child){
                flag2=1;
                break;
            }
        }
        
    }
}

void solve(){
    ll n; cin>>n;
    for (ll i=1; i<=n-1; i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    for (ll i=1; i<=n; i++){
        dfs(i,-1);
    }
    cout<<cost;
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}