#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n,a,q;
    cin>>n>>a>>q;
    string s;
    cin>>s;
    ll temp=a;
    ll maxi=a;
    ll p=a;
    for (ll i=0; i<q; i++){
        if (s[i]=='+'){
            temp++;
            p++;
        }
        else temp--;
        maxi=max(maxi,temp);
    }

    if (p<n){
        cout<<"NO"<<endl;
    }else{
        if (maxi>=n)cout<<"YES"<<endl;
        else cout<<"MAYBE"<<endl;
    }
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