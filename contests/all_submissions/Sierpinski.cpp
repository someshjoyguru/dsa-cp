#include <iostream>
#include <vector>
using namespace std;

// Function to determine the color of the point at (x, y) iteratively
int getColor(int x, int y) {
    // Continue reducing until reaching the smallest triangle
    while (x > 1) {
        // Calculate the largest power of 2 that is <= x
        int level_size = 1;
        while (2 * level_size - 1 < x) {
            level_size *= 2;
        }

        // Midpoint of the current level triangle size
        int mid = level_size / 2;
        int base_x = 2 * level_size - 1;  // Total height of the current level triangle

        // Check if (x, y) falls in the inverted (blue) triangle at the current level
        if (x > base_x - mid && y > x - mid && y <= x) {
            return 0; // Blue point
        }

        // Adjust (x, y) to the coordinates of the next reduced triangle
        if (x > base_x - mid) {
            x -= mid;
            y -= mid;
        }
    }

    // If no blue region is found, the point is red
    return 1;
}

int main() {
    int Q;
    cin >> Q;
    vector<int> results;

    for (int i = 0; i < Q; ++i) {
        int x, y;
        cin >> x >> y;
        results.push_back(getColor(x, y));
    }

    // Output all results
    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
