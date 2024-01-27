#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n;
    cin>>n;
    ll a[n], b[n];
    for (ll i=0;i<n;i++)cin>>a[i];
    for (ll i=0;i<n;i++)cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    reverse(b,b+n);
    ll sum=a[0]+b[0];
    for (ll i=1; i<n; i++){
        if (a[i]+b[i]!=sum){
            cout<<-1<<endl;
            return;
        }
    }
    for (ll i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for (ll i=0; i<n; i++){
        cout<<b[i]<<" ";
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