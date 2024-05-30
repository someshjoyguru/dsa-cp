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
    in(n);
    inv(a,n);
    map<ll, ll> mp;
    ll ans=0;
    for (int i=0; i<n; i++){
        if (mp.find(a[i]-(i+1))!=mp.end()){
            ans+=mp[a[i]-(i+1)];
        }
        mp[a[i]-(i+1)]++;
    }
    cout<<ans<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}