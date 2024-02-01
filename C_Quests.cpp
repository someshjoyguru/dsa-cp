#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n),b(n);
    for (ll i=0; i<n; i++)cin>>a[i];
    for (ll i=0; i<n; i++)cin>>b[i];
    vector<ll> pre(n), maxim(n);
    ll maxi=0, temp=0;
    for (ll i=0; i<n; i++){
        if (i>0)pre[i]=pre[i-1]+a[i];
        else pre[i]=a[i];
        maxim[i]=max(b[i],temp);
        temp=maxim[i];
    }
    temp=0;
    for (ll i=0; i<min(n,k); i++){
        maxi=max(maxi,pre[i]+(k-i-1)*maxim[i]);
    }
    cout<<maxi<<endl;
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