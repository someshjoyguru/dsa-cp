#include <bits/stdc++.h>
using namespace std;

int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {

  if (dp[day][last] != -1) return dp[day][last];

  if (day == 0) {
    int maxi = 0;
    for (int i = 0; i <= 2; i++) {
      if (i != last)
        maxi = max(maxi, points[0][i]);
    }
    return dp[day][last] = maxi;
  }

  int maxi = 0;
  for (int i = 0; i <= 2; i++) {
    if (i != last) {
      int activity = points[day][i] + f(day - 1, i, points, dp);
      maxi = max(maxi, activity);
    }
  }

  return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
  vector<vector<int>> dp(n, vector<int>(4, -1));
  return f(n - 1, 3, points, dp);
}

// Tabulation

int ninjaTraining1(int n, vector<vector<int>>& points) {
  // dp[i][j] represents the maximum points at day i, considering the last activity as j
  vector<vector<int>> dp(n, vector<int>(4, 0));

  // Initialize the DP table for the first day (day 0)
  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

  // Iterate through the days starting from day 1
  for (int day = 1; day < n; day++) {
    for (int last = 0; last < 4; last++) {
      dp[day][last] = 0;
      // Iterate through the tasks for the current day
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          // Calculate the points for the current activity and add it to the
          // maximum points obtained on the previous day (recursively calculated)
          int activity = points[day][task] + dp[day - 1][task];
          // Update the maximum points for the current day and last activity
          dp[day][last] = max(dp[day][last], activity);
        }
      }
    }
  }

  // The maximum points for the last day with any activity can be found in dp[n-1][3]
  return dp[n - 1][3];
}


int main() {
  vector<vector<int>> points = {{10, 40, 70},
                                 {20, 50, 80},
                                 {30, 60, 90}};
  int n = points.size();
  cout << ninjaTraining(n, points);
}