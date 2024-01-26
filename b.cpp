#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> v(n);
    for (ll i=0; i<n; i++)cin>>v[i];
    
    int cnt = 0;
    int curr = 0;
    for (int j = 0; j < n; j++) {
        curr += v[j];
        if (curr >= m) {
            cnt++;
            curr = 0; 
        }
    }
    cout << cnt << endl;

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