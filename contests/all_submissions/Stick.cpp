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
#define pYES cout<<'YES'<<endl;
#define pNO cout<<'NO'<<endl;

void solve(){
    in(n) in(k) in(l)
    if (k>=2*l){
        cout<<(ll)n*4*l*l;
        return;
    }
    ll a=4*l*l;
    ll addons = ((ll)4*l*l-(ll)(2*l-k)*(2*l-k));
    a+=(ll)(n-1)*addons;
    cout<<a;
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}