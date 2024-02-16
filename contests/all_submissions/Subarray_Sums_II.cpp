#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n,x;
    cin>>n>>x;
    vector<ll> vec(n),v(n);
    for (int i=0; i<n; i++)cin>>vec[i];
    ll temp=0;
    for (ll i=0; i<n; i++){
        temp+=vec[i];
        v[i]=temp%n;
    }
    ll cnt=0;
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