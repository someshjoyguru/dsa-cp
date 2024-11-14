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
    in(l) in(a) in(b)
    vll a_up, b_up;
    ll a_right=0, b_left=0;
    f(i,0,a){
        char c; cin>>c; in(x)
        if (c=='U') a_up.push_back(x);
        else a_right++;
    }
    f(i,0,b){
        char c; cin>>c; in(x)
        if (c=='U') b_up.push_back(x);
        else b_left++;
    }
    sort(a_up) sort(b_up)
    ll ans=0;
    if (a_up.size()+a_right>0 && b_left>0)ans+=(a_up.size()+a_right+1)*(b_left+1);
    // cout<<ans<<endl;
    for (ll bb: b_up){
        auto it = upper_bound(all(a_up), bb);
        ll k = distance(it, a_up.end());
        // cout<<k<<" "<<ans<<endl;
        if (k+a_right>0) ans+=(k+a_right+1);
    }
    cout<<ans;
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}