#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(n)for (ll z=0; z<n; z++)
#define f1(z,n)for (ll z=0; z<n; z++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define inv(v,n) vll v(n); f(n)cin>>v[z];
#define pura(v) v.begin(),v.end()
#define sort(v) sort(pura(v));

int mini = INT_MAX;
int cnt=0;
void minCostFunc(int i, vector<int>& col, vector<vector<int>>& c, int cost, int n){
    cnt++;
    if (i==n){
        mini=min(mini, cost);
        return;
    }
    for (int j=0; j<n; j++){
        if (!col[j]){
            col[j]=1;
            minCostFunc(i+1, col, c, cost+c[i][j], n);
            col[j]=0;
        }
    }
    return;
}

void minCostDP(int job, int people, vector<vector<int>>& dp, vector<vector<int>>& c, int n){
    if (job==n || people=0){
        return;
    }
    if (dp[job][people]!=-1) return;
    int peop = people;
    while (peop>0){
        int msb=peop&(~(peop-1));
        
    }
}

void solve(){
    ll n; cin>>n;
    vector<vector<int>> c(n, vector<int>(n, 0));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>c[i][j];
        }
    }
    // vector<int> col(n, 0);
    // minCostFunc(0, col,c, 0, n);
    // cout<<mini<<" "<<cnt;

    // DP on Bitmask
    vector<vector<int>> dp(n, vector<int>((1<<n)-1, -1));
    minCostDP(0, (1<<n)-1, dp, c, n); 
    cout<<dp[n-1][0];
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}