#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n;cin>>n;
    vector<ll> v(n);
    for (ll i=0; i<n; i++)cin>>v[i];
    map<ll,ll> mp;
    mp[0]++;
    ll temp=0;
    for (ll i=0; i<n; i++){
        if (i%2==1)temp+=v[i];
        else temp-=v[i];
        if (mp.find(temp)==mp.end()){
            mp[temp]++;
        }else {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
    return;
}

int main(){
    fastio()
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}