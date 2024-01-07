#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void dfs(ll x, map<ll,vector<ll>>& mp, map<ll,ll>& vis){
    if (vis.find(x)==vis.end()){
        vis[x]++;
    }else return;
    for (auto i : mp[x]){
        dfs(i,mp,vis);
    }
}
void solve1(){
    ll n;
    cin>>n;
    map<ll,vector<ll>> mp;
    for (ll i=0; i<n; i++){
        ll x; cin>>x;
        mp[x]={};
    }
    ll e;
    cin>>e;
    for (ll i=0; i<e; i++){
        ll x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    ll x,y;
    cin>>x>>y;
    map<ll,ll> vis;
    vis[x]++;
    dfs(x,mp,vis);
    if (vis.find(y)!=vis.end()){
        cout<<1;
    }else{
        cout<<0;
    }
}

void solve(){
    ll n;
    cin >> n;
    map<ll,vector<ll>> mp;

    // Initialize the map with empty vectors
    for (ll i = 0; i < n; i++){
        ll x; 
        cin >> x;
        mp[x] = {};
    }

    ll e;
    cin >> e;

    // Read the connections and store them properly
    for (ll i = 0; i < e; i++){
        ll x, y;
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x); // For undirected graph, add both directions
    }

    ll x, y;
    cin >> x >> y;
    map<ll,ll> vis;
    // vis[x]++;
    dfs(x, mp, vis);

    if (vis.find(y) != vis.end()){
        cout << 1;
    } else {
        cout << 0;
    }
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