#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, v1, v2;
        cin >> a >> b >> v1 >> v2;

        int n;
        cin >> n;

        vector<pair<int, int>> pegs(n);
        for (int i = 0; i < n; ++i) {
            cin >> pegs[i].first >> pegs[i].second;
        }

        int earliest_peg = -1;
        double earliest_time = numeric_limits<double>::infinity();

        for (int i = 0; i < n; ++i) {
            int x = pegs[i].first;
            int y = pegs[i].second;

            // Check if the peg satisfies the collinearity condition
            if (y * a == x * b) {
                // Calculate the time when the lasers hit the peg
                double t_hit_x = (v1 == 0) ? numeric_limits<double>::infinity() : (x - a) / static_cast<double>(v1);
                double t_hit_y = (v2 == 0) ? numeric_limits<double>::infinity() : (b - y) / static_cast<double>(v2);

                // Ensure times are non-negative and take the larger of the two
                if (t_hit_x >= 0 && t_hit_y >= 0) {
                    double t_hit = max(t_hit_x, t_hit_y);

                    // Update earliest peg based on the smallest time or smaller x-coordinate on a tie
                    if (t_hit < earliest_time || (fabs(t_hit - earliest_time) < 1e-9 && x < pegs[earliest_peg].first)) {
                        earliest_time = t_hit;
                        earliest_peg = i;
                    }
                }
            }
        }

        // Output the result for the current test case
        if (earliest_peg == -1) {
            cout << -1 << endl;
        } else {
            cout << earliest_peg + 1 << endl; // Output 1-indexed peg position
        }
    }

    return 0;
}
