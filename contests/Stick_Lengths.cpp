#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for (int i=0; i<n; i++)cin>>v[i];
    sort(v.begin(),v.end());
    ll ans1=0, ans2=0;
    ll mid = n/2;
    ll mid2 = n/2-1;
    for (int i=0; i<n; i++){
        ans1+=abs(v[i]-v[mid]);
        ans2+=abs(v[i]-v[mid2]);
    }
    if (n%2){
        cout<<ans1;
        return;
    }else{
        cout<<max(ans1,ans2);
        return;
    }
}

int main(){
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}