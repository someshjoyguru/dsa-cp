#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n,k;
    cin>>n>>k;
    string s="";
    for (ll i=0; i<=k-1; i++){
        s+=('a'+i);
    }
    string r="";
    for (int i=0; i<n; i++){
        r+=s;
    }
    cout<<r<<endl;
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