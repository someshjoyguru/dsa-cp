#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n; cin>>n;
    vector<ll> v(n);
    for (ll i=0; i<n; i++)cin>>v[i];
    ll maxi=INT_MIN;
    for (ll i=0; i<n; i++){
        if (v[i]<0){
            cout<<v[i]<<endl;
            return;
        }
        maxi=max(maxi,v[i]);
    }
    cout<<maxi<<endl;
}

int main(){
    fastio()
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}