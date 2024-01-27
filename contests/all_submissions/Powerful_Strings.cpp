#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, m;
    cin >> n >> m;
    ll pm=n-m+1;
    ll ans =0;
    for (ll i=0; i<pm; i++){
        ans+=pow(26,(n-i)*pm*m);

    }
    cout<<ans;
}

int main(){
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}