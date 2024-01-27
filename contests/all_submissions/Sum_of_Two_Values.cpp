#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,x;
    cin>>n>>x;
    vector<pair<ll,ll>> v;
    for (ll i=0; i<n; i++){
        ll x; cin>>x;
        v.push_back({x,i+1});
    }
    sort(v.begin(),v.end());
    ll i=0,j=n-1;
    while(i<j){
        ll sum = v[i].first+v[j].first;
        if (sum==x){
            cout<<v[i].second<<" "<<v[j].second;
            return;
        }else if (sum<x)i++;
        else j--;
    }
    cout<<"IMPOSSIBLE";
    return;
}

int main(){
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}