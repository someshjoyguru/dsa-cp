#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n,x;
    cin>>n>>x;
    if (x+2>n && x!=0){
        cout<<-1<<endl;
        return;
    }
    for (ll i=n; i>=x+2; i--){
        cout<<i<<" ";
    }
    for (ll i=1; i<=x+1; i++){
        cout<<i<<" ";
    }
    // for (ll i=n; i>=n-x; i--){
    //     cout<<i<<" ";
    // }
    // for (ll i=2; i<=n-x-1; i++){
    //     cout<<i<<" ";
    // }
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