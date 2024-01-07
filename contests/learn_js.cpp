#include <bits/stdc++.h>
using namespace std;
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define INF LLONG_MAX

void dijkstra(map<ll,vector<pair<ll,ll>>>& mp, map<ll,ll>& min, ll start){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, start});

    while(!pq.empty()){
        ll u = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();

        if(cost > min[u]) continue;

        for(auto neighbor : mp[u]){
            ll v = neighbor.first;
            ll weight = neighbor.second;

            if(min[v] > min[u] + weight){
                min[v] = min[u] + weight;
                pq.push({min[v], v});
            }
        }
    }
}

void solve(){
    ll n;
    cin >> n;
    map<ll, vector<pair<ll, ll>>> mp;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        mp[x];
    }
    ll e;
    cin >> e;
    for(ll i = 0; i < e; i++){
        ll x, y, t;
        cin >> x >> y >> t;
        mp[x].push_back({y, t});
        mp[y].push_back({x, t});
    }
    ll x, y;
    cin >> x >> y;
    map<ll, ll> min;
    for(auto node : mp){
        min[node.first] = INF;
    }
    min[x] = 0;

    dijkstra(mp, min, x);
    cout << min[y];
}

int main(){
    fastio()
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
