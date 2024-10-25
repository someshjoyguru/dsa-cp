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
    in(n) in(x)
    vin(a,n)
    ll ans=0, res=0;
    ll j=0;
    ll tmp=0;
    f(i,0,n){
        ans+=a[i];
        while (j<=i && ans>x){
            ans-=a[j];
            j++;
        }
        res+=(i-j+1);
        cout<<j<<" "<<i<<" "<<res<<" "<<ans<<endl;
    }
    cout<<res<<endl;
}

// 999999999 999999998 1000000000 1000000000 500000000
// 999999999 999999999 999999999  999999999  999999999
int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}