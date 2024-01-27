#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for (int i=0; i<n; i++)cin>>v[i];
    sort(v.begin(),v.end());
    if (v[0]!=1){
        cout<<1;
        return;
    }
    ll i=0, k=0;
    while (i<n){
        if (v[i]<=k+1){
            k+=v[i];
        }else{
            cout<<k+1;
            return;
        }
        i++;
    }
    cout<<k+1;
}

int main(){
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}