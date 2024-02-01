#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    // zero
    // >0
    // b>a
    string s; cin>>s;
    ll a,b;
    for (ll i=0; i<s.size()-1; i++){
        if (s[i+1]=='0'){}
        else {
            a=stoi(s.substr(0,i+1));
            b=stoi(s.substr(i+1));
            break;
        }
    }
    if (b>a)cout<<a<<" "<<b<<endl;
    else cout<<-1<<endl;
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