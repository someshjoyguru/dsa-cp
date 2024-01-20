#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n;
    cin>>n;
    if (n==1){
        cout<<1;
        return;
    }
    if (n<=3){
        cout<<"NO SOLUTION";
        return;
    }
    for (ll i=2; i<=n; i+=2)cout<<i<<" ";
    for (ll i=1; i<=n; i+=2)cout<<i<<" ";
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