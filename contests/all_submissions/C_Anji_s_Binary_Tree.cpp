#include <bits/stdc++.h>
using namespace std;

void dfs(int u, string& s, vector<vector<int>> &g, vector<int> &dp) {
    if (g[u][0] == -1 && g[u][1] == -1) {
        dp[u] = 0;
        return;
    }
    if (g[u][0] != -1) {
        dfs(g[u][0], s, g, dp);
        if (s[u] == 'L')
            dp[u] = min(dp[u], dp[g[u][0]]);
        else
            dp[u] = min(dp[u], dp[g[u][0]] + 1);
    }
    if (g[u][1] != -1) {
        dfs(g[u][1], s, g, dp);
        if (s[u] == 'R')
            dp[u] = min(dp[u], dp[g[u][1]]);
        else
            dp[u] = min(dp[u], dp[g[u][1]] + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int N;
        string s;
        cin >> N >> s;
        
        vector<vector<int>> g(N, vector<int>(2, -1));
        for (int i = 0; i < N; ++i) {
            int L, R;
            cin >> L >> R;
            --L, --R;
            g[i][0] = L, g[i][1] = R;
        }
        
        vector<int> dp(N, INT_MAX);
        dfs(0, s, g, dp);
        cout << dp[0] << '\n';
    }
    
    return 0;
}
