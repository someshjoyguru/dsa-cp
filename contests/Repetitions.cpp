#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    string s;
    cin>>s;
    ll n= s.size();
    ll temp=1, maxi=1;
    char c=s[0];
    for (ll i=1; i<n; i++){
        if (s[i]==c){
            temp++;
        }else{
            c=s[i];
            temp=1;
        }
        maxi=max(maxi,temp);
    }
    cout<<maxi;
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