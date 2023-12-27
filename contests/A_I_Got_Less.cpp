#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n,0);
    ll temp=1e9;
    for (ll i=0; i<n; i++){
        cin>>a[i];
        temp=min(temp,a[i]);
    }
    ll s=0;
    for (ll i=0; i<n; i++){
        s+=(a[i]-temp);
    }
    cout<<s<<endl;
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}