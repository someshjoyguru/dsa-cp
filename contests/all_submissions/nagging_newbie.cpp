#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void dfs(ll x, map<ll,vector<ll>>& mp, map<ll,ll>& vis, ll y){
    if (x==y) return;
    if (vis.find(x)==vis.end()){
        vis[x]++;
    }else return;
    for (auto i : mp[x]){
        dfs(i,mp,vis,y);
    }
}
void solve(){
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
    vector<ll> v = mp[y];
    // for (auto i : v){
    //     cout<< i<<" ";
    // }
    // cout<<endl;
    set<ll> st;
    mp.erase(y);
    for (auto i : v){
        dfs(i,mp,vis,y);
        if (vis.find(x)!=vis.end()){
            st.insert(i);
        }
        vis.clear();
    }
    for (auto i : st){
        cout<< i<<" ";
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