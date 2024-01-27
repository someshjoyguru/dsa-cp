#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m, 0));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    ll x=0, y=0;
    ll ans=0;
    for (ll i = 0; i < n; i++) {
        x=0, y=0;
        for (ll j = 0; j < m; j++) {
            if (a[i][j] == 1)x++;
            else y++;
        }
        ans+=(1LL << x)-1;
        ans+=(1LL << y)-1;
    }

    for (ll i = 0; i < m; i++) {
        x=0, y=0;
        for (ll j = 0; j < n; j++) {
            if (a[j][i] == 1)x++;
            else y++;
        }
        ans+=(1LL << x)-1;
        ans+=(1LL << y)-1;
    }
    cout << ans-n*m << endl;


}

int main(){
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}