#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    vector<ll> b(n);
    for (ll i=0; i<n; i++){
        cin>>a[i];
    }
    for (ll i=0; i<n; i++){
        cin>>b[i];
    }
    vector<ll> maxi(n);
    vector<ll> pre(n);
    maxi[0]=b[0];
    pre[0]=a[0];
    for (ll i=1; i<n; i++){
        maxi[i]=max(maxi[i-1],b[i]);
        pre[i]=pre[i-1]+a[i];
    }

    ll ans=0;
    ll rem=0;
    if (k>n){
        rem=k-n;
        k=n;
    }
    ll ind=0;
    for (ll i=k-1; i>=0; i--){
        if (ans<=pre[i]+maxi[i]*(k-i-1)){
            ind=i;
            ans=pre[i]+maxi[i]*(k-i-1);
        }
    }
    if (rem>0){
        ans+=rem*maxi[ind];
        // if (ans<pre[n-1]+maxi[n-1]*(k-n)){
        //     ans=pre[n-1]+maxi[n-1]*(k-n);
        // }
    }
    cout<<ans<<endl;
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}