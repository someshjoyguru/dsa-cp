#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll a,b;
    cin>>a>>b;
    ll diff = abs(b-a);
    ll s=0;
    for (ll i=10; i>=1; i--){
        s+=diff/i;
        diff=diff%i;
    }
    cout<<s<<endl;
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}