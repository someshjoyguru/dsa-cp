#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for(ll i=0; i<n; i++){
        cin >> a[i];
    }
    for(ll i=0; i<m; i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll i=0,j=0;
    ll ans=0;
    while(i<n && j<m){
        if (abs(a[i]-b[j])<=k){
            i++;
            j++;
            ans++;
        }else if (a[i]>b[j]){
            j++;
        }else if (a[i]<b[j]){
            i++;
        }
    }
    cout<<ans;
}

int main(){
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}