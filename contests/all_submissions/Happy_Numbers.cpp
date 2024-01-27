#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll m = 1e9;
vector<bool> dp(m, 0);
vector<bool> dp2(m, 0);

ll sq(ll n){
    unordered_set<ll> visited;
    while (n != 1 && visited.find(n) == visited.end()) {
        visited.insert(n);
        ll temp = 0;
        while (n > 0) {
            temp += (n % 10) * (n % 10);
            n /= 10;
        }
        n = temp;
    }
    // if (n == 1) {
    //     for (auto i : visited) {
    //         if (i < m) {
    //             dp[i] = 1;
    //         }else{
    //             dp2[i%m] = 1;
    //         }
    //     }
    // }
    return n;
}

void solve(){
    ll a,b;
    cin >> a >> b;
    ll x=0;
    for (ll i = a; i <= b; i++) {
        if (i < m && dp[i]) {
            x++;
            continue;
        }
        if (i >= m && dp2[i%m]) {
            x++;
            continue;
        }
        ll n = sq(i);
        if (n == 1) {
            dp[i] = 1;
            x++;
        }
    }
    cout << x << endl;
}

int main(){
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
