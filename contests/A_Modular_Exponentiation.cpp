#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,m;
    cin>>n>>m;
    // m mod (2^n)
    ll ans=1,x=2;
    /*
    2^5

    */
    while (n>0){
        if (n%2){
            ans = ans * x;
            n--;
        }else{
            x = x * x;
            n/=2;
        }
        if (ans>m || x>m || ans>1e8){
            cout<<m<<endl;
            return;
        }
    }
    cout<<m%ans<<endl;
    return;
}

int main(){
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}