#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<double> p(N);
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
    }

    vector<vector<double>> dp(N + 1, vector<double>(N + 1, 0.0));
    dp[0][0] = 1.0;  // Base case: with 0 coins, the probability of 0 heads is 1.

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            // If we don't take the i-th coin (it turns up tails)
            dp[i + 1][j] += dp[i][j] * (1 - p[i]);
            // If we take the i-th coin (it turns up heads)
            dp[i + 1][j + 1] += dp[i][j] * p[i];
        }
    }

    double result = 0.0;
    // Sum up the probabilities of having more heads than tails
    for (int j = (N / 2) + 1; j <= N; ++j) {
        result += dp[N][j];
    }

    cout << fixed << setprecision(10) << result << "\n";
    return 0;
}
