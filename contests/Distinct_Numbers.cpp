#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll ans = 1;
    for(ll i=1; i<n; i++){
        if(v[i] != v[i-1]){
            ans++;
        }
    }
    cout << ans << endl;
}

int main(){
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}