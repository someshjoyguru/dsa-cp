#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(i,a,b) for (ll (i)=(a); (i)<(b); (i)++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define sin(s) string (s); cin>>(s);
#define vin(v,n) vll (v)(n); f(i,0,n)cin>>(v)[i];
#define all(v) (v).begin(),(v).end()
#define sort(v) sort(all(v));
#define pYES cout<<"YES"<<endl;
#define pNO cout<<"NO"<<endl;

void solve(){
    in(n)
    vector<vll> pts, dp(n,vll(3,0));
    f(i,0,n){
        vin(h,3)
        pts.push_back(h);
    }
    f(i,0,3)dp[0][i]=pts[0][i];
    f(i,1,n){
        dp[i][0]=pts[i][0]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=pts[i][1]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=pts[i][2]+max(dp[i-1][0],dp[i-1][1]);
    }
    cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}