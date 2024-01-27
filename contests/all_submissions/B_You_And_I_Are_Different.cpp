#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<string> v(n);
    for (ll i=0; i<n; i++){
        cin>>v[i];
    }
    ll mini=1e9;
    for (ll i=0; i<n-1; i++){
        for (ll j=i+1; j<n; j++){
            ll temp=0;
            for (ll x=0; x<m; x++){
                ll k=(v[i][x]-v[j][x]);
                k=abs(k);
                temp+=k;
            }
            temp=abs(temp);
            
            // cout<<i<<" "<<j<<" "<<temp<<endl;
            mini=min(temp,mini);
        }
    }
    cout<<mini<<endl;
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}