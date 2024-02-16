#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n; cin>>n;
    vector<ll> v(n);
    for (ll i=0; i<n; i++)cin>>v[i];
    vector<ll> pre(n);
    pre[0]=v[0];
    for (ll i=1; i<n; i++)pre[i]=pre[i-1]+v[i];
    // for (auto x: pre)cout<<x<<" ";
    // cout<<endl;
    if (pre[n-1]%n){
        cout<<"NO"<<endl;
        return;
    }
    for (ll i=0; i<n; i++){
        if (pre[i]<pre[n-1]*(i+1)/n){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    return;
    
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