#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    for (ll i=0; i<q; i++){
        char c;
        cin>>c;
        s+=c;
    }
    ll temp=1,maxi=1;
    for (ll i=0; i<n+q; i++){
        if (i>0 && s[i]==s[i-1])temp++;
        else temp=1;
        maxi=max(maxi,temp);
        if (i>=n-1)cout<<maxi<<" ";
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