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
    in(h) in(n)
    vin(a,n)
    vin(c,n)
    ll lo=1, hi=1e18;
    ll mini=hi;
    function<ll(ll)> func = [&](ll ans)->ll{
        ll dam =0;
        f(i,0,n){
            dam+=ceil(ans*(1.0)/c[i]*(1.0))*a[i];
            if (dam >= h) return dam;
        }
        return dam;
    };

    while (lo<=hi){
        ll ans = lo + (hi-lo)/2;
        if (func(ans)>=h){
            mini=ans;
            hi=ans-1;
        }else{
            lo=ans+1;
        }
    }
    cout<<(mini==1e18?1:mini)<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}