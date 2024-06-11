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
    vll h(n+1,0);
    f(i,1,n+1)cin>>h[i];
    vll dp(n+1,0);
    dp[1]=0;
    f(i,2,n+1){
        ll c1=0, c2=INT_MAX;
        c1=abs(h[i]-h[i-1])+dp[i-1];
        if (i-2>0) c2=abs(h[i]-h[i-2])+dp[i-2];
        dp[i]=min(c1,c2);
    }
    cout<<dp[n];
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}