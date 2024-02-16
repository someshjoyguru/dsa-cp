#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n,x;
    cin>>n>>x;
    vector<ll> v(n);
    for (int i=0; i<n; i++)cin>>v[i];
    int cnt=0;
    map<ll,ll> mp;
    ll sum=0;
    mp[0]++;
    for (int i=0; i<n; i++){
        sum+=v[i];
        cnt+=mp[sum-x];
        mp[sum]++;
    }
    cout<<cnt;
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