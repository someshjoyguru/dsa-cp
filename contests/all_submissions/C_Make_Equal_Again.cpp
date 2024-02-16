#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n; cin>>n;
    vector<ll> v(n);
    for (ll i=0; i<n; i++)cin>>v[i];
    ll i=0,j=n-1;
    for (i=0;;){
        if (v[i]==v[0])i++;
        else break;
    }
    ll x=i;
    for (j=n-1;;){
        if (v[j]==v[n-1])j--;
        else break;
    }
    if (n==1){
        cout<<0<<endl;
        return;
    }
    if (v[0]!=v[n-1]){
        cout<<min(n-i,j+1)<<endl;
        return;
    }
    cout<<max(0ll,j-i+1)<<endl;
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