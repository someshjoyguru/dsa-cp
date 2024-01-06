
#include <bits/stdc++.h>
using namespace std;

// Function to check if there is a subset of 'arr' with a sum equal to 'target'

bool subsetSumUtil1(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0)
        return true;

    if (ind == 0)
        return arr[0] == target;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTaken = subsetSumUtil1(ind - 1, target, arr, dp);

    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil1(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTaken || taken;
}

bool subsetSumToK1(int n, int k, vector<int>& arr) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return subsetSumUtil1(n - 1, k, arr, dp);
}

// tabulation 

bool subsetSumToK2(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Base case: If the target sum is 0, we can always achieve it by taking no elements
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // Base case: If the first element of 'arr' is less than or equal to 'k', set dp[0][arr[0]] to true
    if (arr[0] <= k) {
        dp[0][arr[0]] = true;
    }

    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            // If we don't take the current element, the result is the same as the previous row
            bool notTaken = dp[ind - 1][target];

            // If we take the current element, subtract its value from the target and check the previous row
            bool taken = false;
            if (arr[ind] <= target) {
                taken = dp[ind - 1][target - arr[ind]];
            }

            // Store the result in the DP array for the current subproblem
            dp[ind][target] = notTaken || taken;
        }
    }

    return dp[n - 1][k];
}

int main() {
    return 0;
}
