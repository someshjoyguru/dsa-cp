#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(n)for (ll z=0; z<n; z++)
#define f1(z,n)for (ll z=0; z<n; z++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define inv(v,n) vll v(n); f(n)cin>>v[z];
#define pura(v) v.begin(),v.end()
#define sort(v) sort(pura(v));

void solve(){
    ll x, y;
    cin>>x>>y;
    ll sc2x2=y/2;
    ll halfsc2 = y%2;
    ll left = sc2x2*7 + halfsc2*11;
    if (x<=left) cout<<sc2x2+halfsc2<<endl;
    else {
        cout<<sc2x2 + halfsc2 + ceil(((x-left)*1.0)/15.0)<<endl;
    }
}
// 8 1 
// 15 0
int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}