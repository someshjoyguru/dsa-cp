#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long


void solve(){
    int n;
    cin >> n;
    
    vector<vector<ll>> act(3, vector<ll>(n + 1));
    for (int i = 0; i < 3; ++i)
        for (int j = 1; j < n + 1; ++j) 
            cin >> act[i][j];

    vector<vector<vector<vector<ll>>>> dp(n + 1, vector<vector<vector<ll>>>(2, vector<vector<ll>>(2, vector<ll>(2, 0))));

    for (int day = 0; day < n; ++day)
        for (int i : {0, 1})
            for (int j : {0, 1})
                for (int k : {0, 1}){
                    if (i == 0) dp[day + 1][1][j][k] = max(dp[day + 1][1][j][k], dp[day][i][j][k] + act[0][day + 1]);
                    if (j == 0) dp[day + 1][i][1][k] = max(dp[day + 1][i][1][k], dp[day][i][j][k] + act[1][day + 1]);
                    if (k == 0) dp[day + 1][i][j][1] = max(dp[day + 1][i][j][1], dp[day][i][j][k] + act[2][day + 1]);
                    dp[day + 1][i][j][k] = max(dp[day + 1][i][j][k], dp[day][i][j][k]);
                }
            
        
    cout << dp[n][1][1][1] << endl;
}


int main(){
    fastio()
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}