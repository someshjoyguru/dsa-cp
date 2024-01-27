#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

vector<ll> gp[100010];
int vis[100010];

void dfs(ll v){
    vis[v]=1;
    for (auto child : gp[v]){
        if (vis[child]==0) dfs(child);
    }
}
void solve(){
    ll n,m;
    cin>>n>>m;
    for (ll i=0; i<m; i++){
        ll x,y;
        cin>>x>>y;
        gp[x].push_back(y);
        gp[y].push_back(x);
    }
    vector<ll> res;
    for (ll i=1; i<=n; i++){
        if (vis[i]==0){
            dfs(i);
            res.push_back(i);
        }
    }
    cout<<res.size()-1<<endl;
    for (ll i=0; i<res.size()-1; i++){
        cout<<res[i]<<" "<<res[i+1]<<endl;
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