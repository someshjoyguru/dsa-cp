#include <iostream>
#include <vector>
using namespace std;

void generateGrid(int N) {
    vector<vector<int>> grid(N, vector<int>(N));
    int num = 1;

    // Fill the grid cyclically with a shifting pattern
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][(i + j) % N] = num;
            num++;
            if (num > N) num = 1; // Reset to 1 if exceeding N
        }
    }

    // Output the grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        generateGrid(N);
    }
    return 0;
}
