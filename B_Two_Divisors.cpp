#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll a,b;
    cin>>a>>b;
    ll ans = a*b/__gcd(a,b);
    if (ans==b)ans*=(b/a);
    cout<<ans<<endl;
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