#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll l,b;
    cin>>l>>b;
    ll n; cin>>n;
    ll ans=0;
    for (int i=0; i<n; i++){
        ll li,bi;cin>>li>>bi;
        ll x = (li/l)*(bi/b);
        ll y = (li/b)*(bi/l);
        ans+=max(x,y);
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