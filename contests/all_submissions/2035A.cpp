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
    in(n) in(m) in(r) in(c)
    ll tot = (r-1)*m+c-1;
    // tot+=((tot/3)*(m-1));
    // cout<<tot<<endl;
    ll x=(ll)(n-r)*(ll)(m-1);
    x+=((ll)n*m-1-tot);
    cout<<x<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}