#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin>>n;
    vector<ll> a(2*n);
    for(ll i=0; i<2*n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    ll ans=0;
    if (n==1){
        cout<<a[0]<<endl;
        return;
    }
    ll ans1=0;
    for (ll i=2*n-2; i>=0; i-=2)ans+=a[i];
    // for (ll i=2*n-1; i>=0; i-=2)ans1+=a[i];
    cout<<ans<<endl;
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
}