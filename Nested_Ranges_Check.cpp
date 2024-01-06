#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

bool comparator (pair<pair<ll,ll>,ll>& a, pair<pair<ll,ll>,ll>& b){
    if (a.first.first<b.first.first) return true;
    else if (a.first.first==b.first.first && a.first.second>b.first.second) return true;
    else return false;
}
void solve(){
    ll n;
    cin>>n;
    vector<pair<pair<ll,ll>,ll>> v(n);
    for (int i=0; i<n; i++){
        cin>>v[i].first.first;
        cin>>v[i].first.second;
        v[i].second=i;
    }
    sort(v.begin(),v.end(),comparator);
    // for (int i=0; i<n; i++){
    //     cout<<v[i].first.first<<" "<<v[i].first.second<<" "<<v[i].second<<endl;
    // }
    vector<ll> contains(n,0);
    vector<ll> contained(n,0);
    
    ll maxiEnd=0;
    for (int i=0; i<n; i++){
        if (v[i].first.second<=maxiEnd)contained[v[i].second]=1;
        maxiEnd=max(maxiEnd,v[i].first.second);
    }

    ll miniEnd=INT_MAX;
    for (int i=n-1; i>=0; i--){
        if (v[i].first.second>=miniEnd)contains[v[i].second]=1;
        miniEnd=min(miniEnd,v[i].first.second);
    }

    //contains
    for (int i=0; i<n; i++)cout<<contains[i]<<" ";
    cout<<endl;
    //contained
    for (int i=0; i<n; i++)cout<<contained[i]<<" ";
}

int main(){
    fastio()
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}