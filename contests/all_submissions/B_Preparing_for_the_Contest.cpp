#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for (ll i=0; i<k; i++){
        v[i]=i+1;
    }
    for (ll i=k; i<n; i++){
        v[i]=n+k-i;
    }
    for (ll i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}