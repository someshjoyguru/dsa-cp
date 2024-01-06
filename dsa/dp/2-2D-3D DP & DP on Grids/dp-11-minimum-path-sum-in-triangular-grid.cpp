#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i=1; i<n; i++){
            for (int j=0; j<=i; j++){
                int top = (i>j)?triangle[i-1][j]:INT_MAX;
                int top_left = (j>0)?triangle[i-1][j-1]:INT_MAX;
                triangle[i][j]+=min(top,top_left);
            }
        }
        int mini = INT_MAX;
        for (int i=0; i<n; i++){
            mini=min(mini,triangle[n-1][i]);
        }
        return mini;
    }
};

int main(){
    return 0;
}