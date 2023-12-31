#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        int curr;
        int prev=nums[0], prev2;
        // dp[i]-> curr
        // dp[i-1]->prev
        // dp[i-2]->prev2
        
        // from 0 to n-2 (leaving last index)
        for (int i=1;i<n-1; i++){
            int pick = nums[i]+((i>=2)?prev2:0);
            int notPick = prev;
            curr=max(pick,notPick);
            prev2=prev;
            prev=curr;
        }
        int ans1=prev;

        // from 1 to n-1 (leaving last index)
        prev=nums[1];
        for (int i=2;i<n; i++){
            int pick = nums[i]+((i>=3)?prev2:0);
            int notPick = prev;
            curr=max(pick,notPick);
            prev2=prev;
            prev=curr;
        }
        int ans2=prev;
        return max(ans1,ans2);
    }
};

int main(){
    return 0;
}