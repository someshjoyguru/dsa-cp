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
    vin(v,n)
    map<ll,ll> mp;
    f(i,0,n) mp[v[i]]++;
    n=mp.size();
    vll dp(n+1,0), p(n+1,0);
    int k=0;
    // dp[n-1]=p[n-1];
    for (auto [val, freq]: mp)p[k++]=val;
    for (int i=n-2; i>=0; i--){
        ll take = 0, notTake = 0;
        take=p[i]*mp[p[i]];
        if (i+2<n) take+=dp[i+2];
        notTake = dp[i+1];
        dp[i]=max(take, notTake);
    }
    cout<<dp[0];
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}