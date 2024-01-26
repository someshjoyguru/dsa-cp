#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n; cin>>n;
    // a b c 
    // no palindromes of length 3 
    // minimize occurence of c
    string s = "baab";
    if (n<=s.size()){
        cout<<s.substr(0,n);
    }else{
        string temp="";
        while(n-4>0){
            temp+=s;
            n-=4;
        }
        temp+=s.substr(0,n);
        cout<<temp;
    }
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