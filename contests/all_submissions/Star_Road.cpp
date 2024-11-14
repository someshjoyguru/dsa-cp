#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int stars[MAXN];
int lis[MAXN];

int longest_increasing_subsequence(vector<int>& path) {
    vector<int> lis;
    for (int x : path) {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end())
            lis.push_back(x);
        else
            *it = x;
    }
    return lis.size();
}

void dfs(int city, int prev_city, vector<int>& path, int& max_lis) {
    path.push_back(stars[city]);
    max_lis = max(max_lis, longest_increasing_subsequence(path));
    for (int neighbor : adj[city]) {
        if (neighbor != prev_city) {
            dfs(neighbor, city, path, max_lis);
        }
    }
    path.pop_back();
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> stars[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    
    int max_lis = 0;
    for (int city = 0; city < n; ++city) {
        vector<int> path;
        dfs(city, -1, path, max_lis);
    }
    
    cout << max_lis << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
