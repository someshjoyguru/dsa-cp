#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


void solve(){
    ll n; cin>>n;
    vector<ll> price(n+2,-1);
    ll color=1;
    for (ll i=2; i<=(int)sqrt(n+1); i++){
        color=1;
        for (ll j=i; j<=n+1; j+=i){
            price[j]=color;
            color++;
        }
    }
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}