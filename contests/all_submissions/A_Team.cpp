#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin>>n;
    ll c=0;
    for (ll i=0; i<n; i++){
        ll x,y,z;
        cin>>x>>y>>z;
        if (x+y+z>=2)c++;
    }
    cout<<c;
}

int main(){
    ll t;
    // cin>>t;
    t=1;
    while (t--)solve();
}