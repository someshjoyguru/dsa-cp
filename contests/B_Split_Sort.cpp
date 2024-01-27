#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n;cin>>n;
    vector<ll> p(n+1);
    for (ll i=1; i<=n; i++)cin>>p[i];
    vector<ll> v(n+1);
    for (ll i=1; i<=n; i++){
        v[p[i]]=i;
    }
    // for (ll i=1; i<=n; i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    // for (ll i=1; i<=n; i++){
    //     cout<<p[i]<<" ";
    // }
    // cout<<endl;
    ll cnt=0;
    for (ll i=1; i<n; i++){
        if(v[i]>v[i+1])cnt++;
    }
    cout<<cnt<<endl;

    
}
/*
6 4 3 5 2 1


*/

int main(){
    fastio()
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}