#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

const int MOD = 998244353;

int main() {
    int N;
    cin >> N;

    int X, Y;
    cin >> X;
    vector<int> A(X);
    unordered_set<int> setA;
    for (int i = 0; i < X; i++) {
        cin >> A[i];
        setA.insert(A[i]);
    }

    cin >> Y;
    vector<int> B(Y);
    unordered_set<int> setB;
    for (int i = 0; i < Y; i++) {
        cin >> B[i];
        setB.insert(B[i]);
    }

    // Initialize DP array to store number of valid arrangements.
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    dp[0][0] = 1;  // Starting condition: one way to fill zero columns.

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            int k = i - j;  // j items in the first row, k in the second row

            if (j > 0 && (setA.find(j) != setA.end() || setB.find(k) == setB.end())) {
                dp[j][k] = (dp[j][k] + dp[j - 1][k]) % MOD;
            }
            if (k > 0 && (setB.find(k) != setB.end() || setA.find(j) == setA.end())) {
                dp[j][k] = (dp[j][k] + dp[j][k - 1]) % MOD;
            }
        }
    }

    cout << dp[N][N] << endl;
    return 0;
}
