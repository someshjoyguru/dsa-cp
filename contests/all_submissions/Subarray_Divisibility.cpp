#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for (ll i=0; i<n; i++)cin>>v[i];
    ll cnt=0;
    map<ll,ll> mp;
    mp[0]++;
    for (ll i=0; i<n; i++){
        if (i==0)v[i]%=n;
        else v[i]=((v[i-1]+v[i])%n+n)%n;
        cnt+=mp[v[i]];
        mp[v[i]]++;
    }
    cout<<cnt;
}

int main(){
    fastio()
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}