#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll r,g,b;
    cin>>r>>g>>b;
    ll sum=r+g+b;
    ll ans=0;
    ll mini=min({r,g,b});
    ll maxi=max({r,g,b});
    ll mini2=sum-maxi-mini;
    ans+=mini;
    mini2-=(2*mini);
    if (mini2<0){
        maxi-=abs(mini2);
        mini2=0;
    }
    mini=min({maxi,mini2});
    maxi=max({maxi,mini2});
    if (maxi>=mini*2)ans+=mini;
    else ans+=(maxi+mini)/3;
    cout<<ans;
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