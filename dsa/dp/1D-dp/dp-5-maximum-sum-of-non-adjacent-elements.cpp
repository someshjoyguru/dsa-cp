#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Tabulation
// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        for (int i=1;i<n; i++){
            int pick = nums[i]+((i>=2)?dp[i-2]:0);
            int notPick = dp[i-1];
            dp[i]=max(pick,notPick);
        }
        return dp[n-1];
    }
};

// Space optimized
// Time complexity: O(n)
// Space complexity: O(1)

class Solution1 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int curr;
        int prev=nums[0], prev2;
        // dp[i]-> curr
        // dp[i-1]->prev
        // dp[i-2]->prev2
        for (int i=1;i<n; i++){
            int pick = nums[i]+((i>=2)?prev2:0);
            int notPick = prev;
            curr=max(pick,notPick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};

int main(){
    return 0;
}