#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll p =0,m=0;
    for (ll i=0; i<n; i++){
        if (s[i]=='+')p++;
        else m++;
    }
    cout<<abs(p-m)<<endl;
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