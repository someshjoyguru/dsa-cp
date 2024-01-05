#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=1; i<n; i++){
            for (int j=0; j<n; j++){
                int top=(i>0)?matrix[i-1][j]:INT_MAX;
                int top_left=(i>0 && j>0)?matrix[i-1][j-1]:INT_MAX;
                int top_right=(i>0 && j<n-1)?matrix[i-1][j+1]:INT_MAX;
                matrix[i][j]+= min(top,min(top_left,top_right));
            }
        }
        int mini=INT_MAX;
        for (int i=0; i<n; i++){
            mini=min(mini,matrix[n-1][i]);
        }
        return mini;
    }
};

int main(){
    return 0;
}