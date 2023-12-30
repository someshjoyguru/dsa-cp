#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    map<ll,ll> mp;
    mp[7]=1;
    mp[17]=2;
    mp[1]=1;
    map<ll,ll> m;
    m[1]=1;m[7]=1;m[17]=1;m[119]=1;m[289]=1;m[2023]=1;
    ll x=2023;
    for (ll i=0; i<n; i++)cin>>v[i];
    for (ll i=0; i<n; i++){
        if (m[v[i]]){
            
            if (x%v[i]){
                cout<<"NO"<<endl;
                return;
            }
            x=x/v[i];
        }else{
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    cout<<x<<" ";
    for (ll i=0; i<k-1; i++)cout<<1<<" ";
    // for (ll i=0; i<n; i++){
    //     if (mp[v[i]]){
    //         if (v[i]==1)continue;
    //         else{
    //             mp[v[i]]--;
    //         }
    //     }else{
    //         cout<<"NO"<<endl;
    //         return;
    //     }
    // }
    // if (mp[7]+mp[17]>k){
    //     cout<<"NO"<<endl;
    //     return;
    // }
    // cout<<"YES"<<endl;
    // for (ll i=0; i<mp[7]; i++)cout<<7<<" ";
    // for (ll i=0; i<mp[17]; i++)cout<<7<<" ";
    // for (ll i=0; i<k-mp[7]-mp[17]; i++)cout<<1<<" ";
    cout<<endl;
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