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
    vin(a,n)
    vll dp(n+1,0);

    // function<ll(ll)> fa = [&](ll i) -> ll{
    //     if (i<0) return 0;
    //     ll c1 = a[i] + fa(i - 1);
    //     ll c2 = abs(a[i] + fa(i - 1));
    //     if (abs(c1)>abs(c2)) return c1;
    //     else return c2;
    // };
    // cout << abs(fa(n-1)) << endl;
     for (int i = 0; i < n; i++) {
        dp[i+1] = max(dp[i] + a[i], abs(dp[i] + a[i]));
    }

    cout << dp[n] << endl;
    // f(i,0,n) cout<<dp[i]<<" ";
    // cout<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}