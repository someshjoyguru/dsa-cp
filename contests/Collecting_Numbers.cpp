#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for (int i=0; i<n; i++){
        cin>>v[i];
        v[i]--;
    }
    vector<ll> loc(n);
    for (int i=0; i<n; i++)loc[v[i]]=i;
    ll ans=1;
    for (int i=1; i<n; i++){
        if (loc[i]<loc[i-1])ans++;
    }
    cout<<ans;
}

int main(){
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}