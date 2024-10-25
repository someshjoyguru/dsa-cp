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
    in(l) in(r)
    vll dp(20,0);
    ll maxi=0;
    for (int i=l; i<=r; i++){
        for (int j=0; j<18; j++){
            dp[j]+=(((1<<j) & i))?1:0;
            maxi=max(maxi, dp[j]);
            // cout<<maxi<<" ";
        }
        // cout<<endl;
    }
    cout<<r-l+1-maxi<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}