#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for (int i=0; i<n; i++)cin>>v[i];
    ll temp=0, maxi=v[0];
    for (ll i=0; i<n; i++){
        if (temp<0)temp=0;
        temp+=v[i];
        maxi=max(maxi,temp);
    }
    cout<<maxi;
}

int main(){
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}