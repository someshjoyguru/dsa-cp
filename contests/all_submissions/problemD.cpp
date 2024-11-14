#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

struct Peg {
    int x, y;
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, v1, v2;
        cin >> a >> b >> v1 >> v2;

        int n;
        cin >> n;
        vector<Peg> pegs(n);

        for (int i = 0; i < n; ++i) {
            cin >> pegs[i].x >> pegs[i].y;
        }

        int result = -1;
        double min_time = numeric_limits<double>::infinity();

        for (int i = 0; i < n; ++i) {
            int x_p = pegs[i].x;
            int y_p = pegs[i].y;

            // Check if the peg (x_p, y_p) lies on the initial line y = -(b/a) * x + b
            if (a * (b - y_p) == b * (a - x_p)) {
                // Calculate time to reach this peg
                double time_x = (x_p - a) / static_cast<double>(v1);
                double time_y = (b - y_p) / static_cast<double>(v2);

                if (fabs(time_x - time_y) < 1e-9 && time_x >= 0) { // Ensure both times are equal and positive
                    if (time_x < min_time || (fabs(time_x - min_time) < 1e-9 && x_p < pegs[result].x)) {
                        min_time = time_x;
                        result = i;
                    }
                }
            }
        }

        // Output the index of the first peg (1-indexed) or -1 if none are hit
        cout << (result == -1 ? -1 : result + 1) << endl;
    }

    return 0;
}
