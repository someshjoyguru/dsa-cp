#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n,q;
    cin>>n>>q;
    vector<ll> v(n);
    for (ll i=0; i<n; i++){
        cin>>v[i];
        if (i>0)v[i]+=v[i-1];
    }
    for (ll i=0; i<q; i++){
        ll x,y;
        cin>>x>>y;
        if (x<2) cout<<v[y-1]<<endl;
        else cout<<v[y-1]-v[x-2]<<endl;
    }
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