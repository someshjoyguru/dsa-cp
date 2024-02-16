#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    string s; cin>>s;
    string ans="";
    for (int i=0; i<s.size(); i++){
        if (i==0 && s[i]=='?')ans+='0';
        else if (i==0)ans+=s[i];
        else if (s[i]=='?')ans+=ans[i-1];
        else ans+=s[i];
    }
    cout<<ans<<endl;
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