#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Cell {
    int row, col, elevation;
    Cell(int r, int c, int e) : row(r), col(c), elevation(e) {}
};

struct Edge {
    int row, col, weight;
    Edge(int r, int c, int w) : row(r), col(c), weight(w) {}
    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

int dijkstra(vector<vector<int>>& elevations, int n, int m) {
    vector<vector<int>> distances(n, vector<int>(m, INF));
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    // Start with the cell with the highest elevation
    pq.push(Edge(0, 0, elevations[0][0]));
    distances[0][0] = elevations[0][0];

    // Possible directions: right, left, down, up
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!pq.empty()) {
        Edge current = pq.top();
        pq.pop();

        for (int i = 0; i < 4; ++i) {
            int newRow = current.row + dx[i];
            int newCol = current.col + dy[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                int weight = elevations[newRow][newCol];
                int newDistance = max(current.weight, distances[current.row][current.col]);

                if (newDistance < distances[newRow][newCol]) {
                    distances[newRow][newCol] = newDistance;
                    pq.push(Edge(newRow, newCol, newDistance));
                }
            }
        }
    }

    // The maximum flow value is the distance to the drain cell
    return distances[n - 1][m - 1];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> elevations(n, vector<int>(m));

    // Read elevations
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> elevations[i][j];
        }
    }

    int maxFlow = dijkstra(elevations, n, m);
    cout << maxFlow << endl;

    return 0;
}
