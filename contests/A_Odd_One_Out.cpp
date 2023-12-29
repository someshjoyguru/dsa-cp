#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    vector<ll> v(3);
    for (int i=0 ; i<3; i++)cin>>v[i];
    sort(v.begin(),v.end());
    if (v[0]==v[1])cout<<v[2]<<endl;
    else if (v[1]==v[2])cout<<v[0]<<endl;
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}