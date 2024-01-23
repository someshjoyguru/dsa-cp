#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long


void dfs(int i, int j, vector<vector<char>>& mp, vector<vector<ll>>& dp){
    dp[i][j]=1;
    mp[i][j]='#';
    int n=dp.size();
    int m =dp[0].size();
    if (i>0 && mp[i-1][j]=='.') dfs(i-1,j,mp,dp);
    if (j>0 && mp[i][j-1]=='.') dfs(i,j-1,mp,dp);
    if (i<n-1 && mp[i+1][j]=='.') dfs(i+1,j,mp,dp);
    if (j<m-1 && mp[i][j+1]=='.') dfs(i,j+1,mp,dp);
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<char>> mp(n,vector<char>(m));
    vector<vector<ll>> dp(n,vector<ll>(m,0));
    for (int i=0; i<n; i++){
        string s;cin>>s;
        for (int j=0; j<m; j++){
            mp[i][j]=s[j];
            if (s[j]=='#') dp[i][j]=1;
        }
    }
    ll cnt =0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (mp[i][j]=='.') {
                cnt++;
                dfs(i,j,mp,dp);
            }
        }
    }
    cout<<cnt;
}

int main(){
    fastio()
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}