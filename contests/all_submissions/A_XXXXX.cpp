#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,x;
    cin>>n>>x;
    vector<ll> v(n);
    for (ll i=0; i<n; i++){
        cin>>v[i];
    }
    bool l=true;
    for (ll i=0; i<n; i++){
        for (ll j=n-1; j>=i; j--){
            if (accumulate(v.begin()+i,v.begin()+j,0)%x!=0){
                cout<<j-i+1<<endl;
                l=false;
                break;
            }
        }
        if (!l)break;
    }
    if (l) cout<<-1<<endl;
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}