#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
4 1 2 3

*/
void solve(){
   ll n; cin>>n;
   if (n<=9){
    cout<<(n*(n+1)/2)<<endl;
    return;
   }
//    ll x=45;
//    ll a=n/9;
//    ll ans=a*x;
//    if (a>2)ans+=(a-2)*(a-1)/2*9;
//    ll rem=n%9;
//    if (n>=2 && rem!=0)ans+=min(n-2,rem)*9;
//    else 
//    cout<<ans<<endl;
    ll ans=n/9*45+n%9*(n%9+1)/2;
    cout<<ans<<endl;
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
}