#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n,0);
    for(ll i=0;i<n-1;i++){
        ll x,y;
        cin>>x>>y;
        v[x-1]++;
        v[y-1]++;
    }
    ll c=0;
    for (ll i = 0; i < n; i++)
    {
        if(v[i]==1){
            c++;
        }
    }
    cout<<ceil(c/2.0)<<endl;
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}