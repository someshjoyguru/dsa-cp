#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long double

void solve(){
    lld a,b,c,d;
    cin >> a >> b >> c >> d;
    cout<<setprecision(12)<<fixed;
    cout<<(a/b)/(1-(1-a/b)*(1-c/d))<<endl;
}

int main(){
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}