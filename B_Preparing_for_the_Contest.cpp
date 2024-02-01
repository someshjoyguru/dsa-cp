#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n,k;
    cin>>n>>k;
    ll i=1;
    for (; i<=k; i++){
        cout<<i<<" ";
    }
    for (i=n;i>k; i--){
        cout<<i<<" ";
    }
    cout<<endl;
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