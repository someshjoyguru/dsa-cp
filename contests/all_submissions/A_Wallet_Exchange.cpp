#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll x,y;
    cin>>x>>y;
    if (abs(x-y)&1){
        cout<<"Alice"<<endl;
    }else{
        cout<<"Bob"<<endl;
    }
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