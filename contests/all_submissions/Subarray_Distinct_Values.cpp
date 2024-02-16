#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long
 
void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for (ll i=0; i<n; i++)cin>>v[i];
    map<ll,ll> mp;
    ll i=0,j=0;
    ll cnt=0;
    for (int i=0; i<n; i++){
        while (j<n && (mp.size()<k || mp.count(v[j])>0)){
            mp[v[j]]++;
            j++;
        }
        cnt+=j-i;
        mp[v[i]]--;
        if (mp[v[i]]==0)mp.erase(v[i]);
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
