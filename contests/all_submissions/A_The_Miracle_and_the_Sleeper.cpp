#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll l,r;
    cin>>l>>r;
    // 1 10 -> 4
    // 1 9
    if (r<l*2) cout << r - l << endl;
    else cout << (r - 1) / 2 << endl;
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