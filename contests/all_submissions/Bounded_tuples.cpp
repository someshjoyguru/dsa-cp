#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>
#include <algorithm>

using namespace std;

const int MOD = 998244353;
const int64_t INF = 1e18;
int N, M;
vector<pair<int64_t, int64_t>> constraints;
vector<vector<int>> subsets;
vector<vector<int>> adj;

bool checkInfinite() {
    vector<bool> visited(N, false);

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;

            bool hasHighInfinity = false;
            bool hasFiniteLimit = false;

            while (!q.empty()) {
                int v = q.front();
                q.pop();

                for (int j = 0; j < M; ++j) {
                    if (find(subsets[j].begin(), subsets[j].end(), v) != subsets[j].end()) {
                        int64_t low = constraints[j].first;
                        int64_t high = constraints[j].second;

                        if (high == INF) hasHighInfinity = true;
                        if (high != INF) hasFiniteLimit = true;
                    }
                }

                for (int neighbor : adj[v]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }

            if (hasHighInfinity && !hasFiniteLimit) {
                return true;
            }
        }
    }

    return false;
}

bool satisfiesConstraints(const vector<int>& V) {
    for (int i = 0; i < M; ++i) {
        int64_t low = constraints[i].first;
        int64_t high = constraints[i].second;
        int64_t sum = 0;

        for (int idx : subsets[i]) {
            sum += V[idx];
        }

        if (sum < low || sum > high) {
            return false;
        }
    }
    return true;
}

int countValidAssignments(int index, vector<int>& V) {
    if (index == N) {
        return satisfiesConstraints(V) ? 1 : 0;
    }

    int count = 0;
    for (int value = 0; value <= 10; ++value) {
        V[index] = value;
        count += countValidAssignments(index + 1, V);
        if (count >= MOD) {
            count -= MOD;
        }
    }
    return count;
}

int main() {
    cin >> N >> M;
    constraints.resize(M);
    subsets.resize(M);
    adj.resize(N);

    for (int i = 0; i < M; ++i) {
        int64_t low, high;
        int K;
        cin >> low >> high >> K;

        constraints[i] = {low, high};
        subsets[i].resize(K);

        for (int j = 0; j < K; ++j) {
            cin >> subsets[i][j];
            --subsets[i][j];
        }

        for (int j = 0; j < K; ++j) {
            for (int l = j + 1; l < K; ++l) {
                adj[subsets[i][j]].push_back(subsets[i][l]);
                adj[subsets[i][l]].push_back(subsets[i][j]);
            }
        }
    }

    if (checkInfinite()) {
        cout << "infinity" << endl;
    } else {
        vector<int> V(N, 0);
        int result = countValidAssignments(0, V);
        cout << result << endl;
    }

    return 0;
}
