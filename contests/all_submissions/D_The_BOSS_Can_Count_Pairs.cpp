#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n; cin>>n;
    vector<ll> a(n,0),b(n,0);
    for (ll i=0; i<n; i++)cin>>a[i];
    for (ll i=0; i<n; i++)cin>>b[i];
    ll cnt=0;
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (a[i]*a[j]==b[i]+b[j]){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
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