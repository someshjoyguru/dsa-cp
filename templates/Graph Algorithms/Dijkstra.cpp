// O(VlogV + ElogV)
// Single Source Shortest Path

void Dijkstra(int s, int n, vector<ll> &dist, vector<int> &parent, const vector<vector<pair<int, ll>>> &adj) {
    dist.assign(n, 1e9);
    parent.assign(n, -1);
    dist[s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push({0, s});

    while (!q.empty()) {
        pair<ll, int> here = q.top();
        q.pop();
        int v = here.second;
        ll d_v = here.first;

        if (d_v != dist[v])
            continue;

        for (const auto &edge : adj[v]) {
            int to = edge.first;
            ll len = edge.second;

            if (dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
                parent[to] = v;
                q.push({dist[to], to});
            }
        }
    }
}