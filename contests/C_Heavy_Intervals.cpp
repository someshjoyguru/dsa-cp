#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    vector<ll> l(n), r(n), c(n);

    for (ll i = 0; i < n; ++i) {
        cin >> l[i];
    }

    for (ll i = 0; i < n; ++i) {
        cin >> r[i];
    }

    for (ll i = 0; i < n; ++i) {
        cin >> c[i];
    }

    
    cout << ans << endl;
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}