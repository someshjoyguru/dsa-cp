#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n; cin>>n;
    vector<ll> v(n);
    for (ll i=0; i<n; i++)cin>>v[i];
    ll q; cin>>q;

    vector<ll> pre(n,-1);
    pre[n-1]=n;
    for (ll i=n-2; i>=0; i--){
        if (v[i]==v[i+1])pre[i]=pre[i+1];
        else pre[i]=i+1;
    }
    
    while (q--){
        ll l,r;
        cin>>l>>r;

        l--; r--;
        
        if (pre[l]>r)cout<<-1<<" "<<-1<<endl;
        else cout<<l+1<<" "<<1+pre[l]<<endl;
    }
    cout<<endl;
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