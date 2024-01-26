#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    string s; cin>>s;
    ll n=s.size();
    ll ch=0,cv=0;
    for (ll i=0; i<n;i++){
        if (s[i]=='1'){
            cout<<1<<" "<<ch+1<<endl;
            ch=(ch+2)%4;
        }else{
            cout<<2<<" "<<cv+1<<endl;
            cv=(cv+1)%4;
        }
    }
}

int main(){
    fastio()
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}