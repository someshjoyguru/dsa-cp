#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    string s; cin>>s;
    ll a=0,b=0;
    for (ll i=0; i<s.size(); i++){
        if (s[i]=='1')a++;
        else b++;
    }
    for (ll i=0; i<s.size(); i++){
        if (s[i]=='1')b--;
        else a--;
        if (a<0 or b<0){
            cout<<s.size()-i<<endl;
            return;
        }
    }
    cout<<0<<endl;

}

// 111100
// 00xxxx
// 00xx11

int main(){
    fastio()
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}