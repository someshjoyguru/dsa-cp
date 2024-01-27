#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dfs(int node,vector<bool> &vis, vector<int> &cost, vector<vector<int>> &adj)
{

    ll z = cost[node];
    vis[node]= true;
    for (int ch : adj[node])
    {
        if (!vis[ch])
        {
            vis[ch] = true;
            ll x = dfs(ch, vis, cost, adj);
            z = min(z, x);
        }
    }
    return z;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> cost(n);
    adj.reserve(n);
    cost.reserve(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n, 0);
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            s += dfs(i, vis, cost, adj);
        }
    }
    cout << s;
    return 0;
}