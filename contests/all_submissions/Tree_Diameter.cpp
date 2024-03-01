#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll s;

void dfsUtil(ll node, ll count, bool visited[], ll &maxCount, vector<vector<ll>>& adj) {
    visited[node] = true;
    count++;
    for (auto i : adj[node]) {
        if (!visited[i]) {
            if (count >= maxCount) {
                maxCount = count;
                s=i;
            }
            dfsUtil(i, count, visited, maxCount, adj);
        }
    }
}

void dfs(ll node, ll n, vector<vector<ll>>& adj, ll &maxCount) {
    bool visited[n + 1];
    ll count = 0;
    for (ll i = 1; i <= n; ++i)
        visited[i] = false;

    dfsUtil(node, count + 1, visited, maxCount, adj);
}

ll diameter(vector<vector<ll>>& adj, ll n) {
    ll maxCount = INT_MIN;
    dfs(1, n, adj, maxCount);
    dfs(s, n, adj, maxCount);
    return maxCount;
}

void solve(){
    ll n;
    cin >> n;
    vector<vector<ll>> adj(n + 1);
    for (ll i=0; i<n-1; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (n==1)cout<<0;
    else cout << diameter(adj, n)-1;
    return;
}

int main(){
    fast;
    ll t=1;
    // cin >> t;
    while(t--)solve();
    return 0;
}
