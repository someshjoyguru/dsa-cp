#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll x,y;
    cin>>x>>y;
    if (x>y)swap(x,y);
    // while(x>0){
    //     ll temp=x;
    //     x=y-x;
    //     y=temp;
    //     if (x>y)swap(x,y);
    // }
    if (y%x)cout<<y%x<<endl;
    else cout<<x<<endl;
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