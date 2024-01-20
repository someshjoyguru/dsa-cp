#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for (ll i=0; i<n; i++)cin>>v[i];
    ll sum=0;
    for (ll i=1; i<n; i++){
        if (v[i]<v[i-1]){
            sum+=(v[i-1]-v[i]);
            v[i]=v[i-1];
        }
    }
    cout<<sum;
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