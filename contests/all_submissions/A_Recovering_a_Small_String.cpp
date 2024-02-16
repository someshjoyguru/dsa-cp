#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n; cin>>n;
    n-=3;
    string s="aaa";
    if (n>=25){
        s[2]+=25;
        n-=25;
    }else{
        s[2]+=n;
        cout<<s<<endl;
        return;
    }

    if (n>=25){
        s[1]+=25;
        n-=25;
    }else{
        s[1]+=n;
        cout<<s<<endl;
        return;
    }

    s[0]+=n;
    cout<<s<<endl;
    return;
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