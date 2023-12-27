#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<int> v(n);
    ll x,k=1;
    for (ll i=0; i<n; i++)cin>>v[i];
    for (ll i=0; i<n; i++){
        if (v[i]!=i){
            if(k){
                x=i;
                k--;
            }
            else x&=i;
        }
        // cout<<x<<endl;
    }
    cout<<x<<endl;
}
// 5 6 4
// 101
// 110
// 100

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}