#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n; cin>>n;
    vector<ll> a(n);
    for (ll i=0; i<n; i++)cin>>a[i];
    ll ans=0;
    for (ll i=1; i<=n; i++){
        if (n%i==0){
            ll k=n/i,g=0;
            for (ll j=0; j<k; j++){
                ll diff =0;
                for (ll l=j; l<n; l+=k){
                    diff=__gcd(diff,abs(a[j]-a[l]));
                }
                g=__gcd(g,diff);
            }
            ans+=(g!=1);
        }
    }
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