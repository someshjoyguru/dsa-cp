#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for (ll i=0; i<n; i++)cin>>a[i];
    ll mini=INT_MAX;
    for (ll i=0; i<n; i++){
        if (a[i]>=k)mini=min(mini,a[i]%k);
    }
    if (mini==INT_MAX)cout<<-1<<endl;
    else cout<<mini<<endl;
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