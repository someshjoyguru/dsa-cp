#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(i,a,b) for (ll (i)=(a); (i)<(b); (i)++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define sin(s) string (s); cin>>(s);
#define inv(v,n) vll (v)(n); f(i,0,n)cin>>(v)[i];
#define all(v) (v).begin(),(v).end()
#define sort(v) sort(pura(v));

void solve(){
    in(n);
    sin(s);
    ll a00=0, a11=0, a10=0, a01=0;
    f(i,0,n-1){
        if (s[i]=='0' && s[i+1]=='0') a00++;
        else if (s[i]=='1' && s[i+1]=='1') a11++;
        else if (s[i]=='0' && s[i+1]=='1') a01++;
        else a10++;
        i++;
    }
    ll ans = (a11+a00)*2 + ((a10>=2)?2:((a10==1)?1:0)) + ((a01!=0)?2:0);
    cout<<ans<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}