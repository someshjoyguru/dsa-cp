#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<int> v(n);
    ll x=0, p=1;
    for (ll i=0; i<n; i++){
        cin>>v[i];
        if (p){
            x=v[i];
            p--;
        }else{
            x&=v[i];
        }
    }
    vector<bool> ans(32);
    for (ll i=0; i<=30; i++){
        if ((x & (1 << i)) == 1){
            ans[i]=1;
        }
    }
    ll req;
    for (ll i=30; i>=0; i--){
        req=0;
        for (ll j=0; j<n; j++){
            if ((v[j]&(1<<i))==0){
                req++;
            }
        }
        if (req<=k){
            ans[i]=true;
            k-=req;
        }
    }
    ll c=0;
    for (ll i=0; i<=30; i++){
        if (ans[i]){
            c|=(1<<i);
        }
    }
    cout<<c<<endl;
}
// 3 1 3 1
// 11
// 01
// 11
// 01


int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}