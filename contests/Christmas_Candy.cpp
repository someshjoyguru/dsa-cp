#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for (ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=0;
    ll i=0,j=1;
    while(true){
        if (a[i]>a[j]){
            ans++;
            j++;
        }else{
            i=j;
            j++;
        }
        if (j==n){
            cout<<ans<<"\n";
            return;
        }
    }

}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}