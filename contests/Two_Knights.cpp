#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n; cin>>n;
    for (ll i=1; i<=n; i++){
        ll ncr=i*i*(i*i-1)/2;
        cout<<ncr-4*(i-1)*(i-2)<<endl;
    }
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