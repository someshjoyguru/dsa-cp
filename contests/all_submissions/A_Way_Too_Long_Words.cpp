#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    string s;
    cin>>s;
    ll n= s.size();
    if (n<=10){
        cout<<s<<endl;
    }else{
        string st=s.substr(0,1);
        st+=to_string(n-2);
        st+=s.substr(n-1,1);
        cout<<st<<endl;
    }
}

int main(){
    ll t;
    // t=1;
    cin>>t;
    while (t--)solve();
}