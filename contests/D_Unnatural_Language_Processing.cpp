#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n; cin>>n;
    string k; cin>>k;
    string s="";
    map<char,ll> mp;
    mp['a']++;
    mp['e']++;
    mp['i']++;
    mp['o']++;
    mp['u']++;
    for (int i=0; i<n; i++){
        if (mp.find(k[i])==mp.end())s+='c';
        else s+='v';
    }
    // cvcvc
    string ans="";
    for (ll i = n - 1; i >= 0;) {
        if (i >= 2) {
            if (s.substr(i - 2, 3) == "cvc") {  
                ans += k[i];
                ans+=k[i-1];
                ans+=k[i-2];
                ans+='.';
                i -= 3;
            } else if (s.substr(i - 1, 2) == "cv") {
                ans += k[i];
                ans+=k[i-1];
                ans+='.';
                i -= 2;
            }
        } else {
            ans += k[i];
            ans+=k[i-1];
            ans+='.';
            break;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.substr(1)<<endl;
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