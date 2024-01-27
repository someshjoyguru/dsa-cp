#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n; cin>>n;
    vector<ll> v(n);
    
    ll maxiI=n-1,miniI=0;
    
    for (ll i=0; i<n; i++)cin>>v[i];
    
    for (ll i=1; i<n; i++)
        if (v[i]<=v[miniI])miniI=i;
    for (ll i=n-2; i>=0; i--)
        if (v[i]>=v[maxiI])maxiI=i;

        
    ll ans = n-1+maxiI-miniI;
    if (maxiI>miniI)ans--;
    if (n==1) cout<<0;
    else cout<<ans;
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