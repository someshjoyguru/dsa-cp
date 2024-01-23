#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long
ll const mod =1e9+7;
ll cnt=0;
// set<vector<ll>> ans;
int dp[501][501]={-1};
 
void func(int target, int ind, int n, ll curr){
    if (target==0){
        curr%=mod;
        cnt%=mod;
        cnt++;
        return;
    }
    if (ind==n+1)return;
    // pick
    curr+=ind;
    cnt%=mod;
    curr%=mod;
    func(target-ind, ind+1, n, curr);
    curr%=mod;
    cnt%=mod;
    curr-=ind;
    // not pick
    func(target,ind+1,n,curr);
}
void solve(){
    ll n;
    cin>>n;
    if ((n*(n+1))%4) cout<<0;
    else {
        ll target = (n*(n+1))/4;
        // vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
        ll sum =target;
        func(sum,1,n,0);
        cnt%=mod;
        cout<<cnt/2;
    }
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
