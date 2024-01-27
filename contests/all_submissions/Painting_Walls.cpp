#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll x,y,z;
    cin>>x>>y>>z;
    ll unit_can_paint=z/2;
    ll area=x*y;
    cout<<unit_can_paint/area<<"\n";
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}