#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

vector<vector<int>> adj;
vector<long long> weights;
vector<long long> dp, subtree_size, result;
int N;

void dfs(int node, int parent) {
    dp[node] = weights[node - 1]; // Initialize with node's own weight
    subtree_size[node] = 1;       // Start subtree size with itself
    
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node);
            dp[node] += dp[neighbor];
            dp[node] %= MOD;
            subtree_size[node] += subtree_size[neighbor];
        }
    }
}

void dfs_result(int node, int parent, long long parent_contrib) {
    long long total_weight = (dp[node] + parent_contrib) % MOD;
    
    for (int i = 1; i <= N; ++i) {
        if (subtree_size[node] >= i) {
            result[i - 1] = (result[i - 1] + total_weight) % MOD;
        }
    }
    
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            long long new_contrib = (parent_contrib + dp[node] - dp[neighbor] + MOD) % MOD;
            dfs_result(neighbor, node, new_contrib);
        }
    }
}

int main() {
    cin >> N;
    adj.resize(N + 1);
    weights.resize(N);
    dp.resize(N + 1);
    subtree_size.resize(N + 1);
    result.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> weights[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);
    dfs_result(1, -1, 0);

    for (int i = 0; i < N; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
