#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,x;
    cin>>n>>x;
    vector<ll> v(n);
    for (int i=0; i<n; i++)cin>>v[i];
    sort(v.begin(),v.end());
    ll i=0, j=n-1, ans=0;
    while (i<j){
        if (v[i]+v[j]<=x){
            ans++;
            i++;
            j--;
        }else{
            ans++;
            j--;
        }
        if (i==j){
            ans++;
            break;
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