#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool comparator(pair<ll,ll>& a,pair<ll,ll>& b){
    return a.second<b.second;
}
void solve(){
    ll n;
    cin>>n;
    vector<pair<ll,ll>> v;
    for (ll i=0; i<n; i++){
        ll x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),comparator);
    ll ans =1,last=v[0].second;
    for (ll i=1; i<n; i++){
        if (v[i].first>=last){
            ans++;
            last=v[i].second;
        }
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