#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    string ans="";
    ll k=n/2+1;
    ll already_win=0;
    for (ll i=0; i<n; i++)ans+="P";
    for (ll i=0; i<n; i++){
        if (s[i]=='R')already_win++;
        else if (s[i]=='P'){}
        // else already_win--;
    }
    if (already_win>=k){
        cout << ans << endl;
        return;
    }
    // k=n/2+1;
    // k-=draw;
    // k-=already_win;
    ll x=0;
    for (ll i=n-1; i>=0; i--){
        if (s[i]=='S'){
            ans[i]='R';
            x++;
        }else if (s[i]=='R'){
            // ans[i]='P';
        }
        else if (s[i]=='P'){
            ans[i]='S';
            x++;
        }
        if (x+already_win>=k)break;
    }
    cout << ans << endl;
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}