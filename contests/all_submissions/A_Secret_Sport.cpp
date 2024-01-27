#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll a=0, b=0;
    for (ll i=0; i<n; i++){
        if (s[i]=='A') a++;
        else b++;
    }
    if (a>b){
        cout<<"A"<<endl;
    }else if (b>a){
        cout<<"B"<<endl;
    }else{
        cout<<"?"<<endl;
    }
}
// sets ->plays
// X wins in plays - winner
int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}