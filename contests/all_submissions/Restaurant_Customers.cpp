#include <bits/stdc++.h>
using namespace std;
#define ll long long

// bool comparator(pair<ll,ll>& a, pair<ll,ll>& b){
//     return a.second<b.second;
// }

void solve(){
    ll n; cin>>n;
    vector<pair<ll,ll>> v;
    for (int i=0; i<n; i++){
        ll x,y;
        cin>>x>>y;
        v.push_back({x,1});
        v.push_back({y,-1});
    }
    sort(v.begin(),v.end());
    ll maxi=0,temp=0;
    for (int i=0; i<2*n; i++){
        temp+=v[i].second;
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