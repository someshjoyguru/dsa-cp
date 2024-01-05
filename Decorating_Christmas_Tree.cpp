#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n,x,y;
    cin>>n>>x>>y;
    ll c1 = y/3;
    if (c1<=x){
        x-=c1;
        n-=c1;
    }else{
        n-=x;
        x=0;
    }
    ll c2= x/2;
    if (c2>=n)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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