#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Union-Find (Disjoint Set Union) structure to manage components
class UnionFind {
public:
    vector<int> parent, rank;
    int components;

    UnionFind(int n) : parent(n), rank(n, 0), components(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            components--;
        }
    }
};

int countComponentsForLength(const string& S, int len) {
    int n = S.size();
    UnionFind uf(n);

    unordered_set<string> seen;
    for (int i = 0; i <= n - len; ++i) {
        string sub = S.substr(i, len);
        if (seen.find(sub) == seen.end()) {
            for (int j = i; j < i + len - 1; ++j) {
                uf.unite(j, j + 1);
            }
            seen.insert(sub);
        }
    }

    return uf.components;
}

vector<int> findMinLengthsForComponents(const string& S) {
    int n = S.size();
    vector<int> result(n, 0);

    for (int k = 1; k <= n; ++k) {
        int left = 1, right = n;
        int answer = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int components = countComponentsForLength(S, mid);

            if (components <= k) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (answer && countComponentsForLength(S, answer) == k) {
            result[k - 1] = answer;
        }
    }

    return result;
}

int main() {
    string S;
    cin >> S;

    vector<int> result = findMinLengthsForComponents(S);
    for (int length : result) {
        cout << length << " ";
    }
    cout << endl;

    return 0;
}
