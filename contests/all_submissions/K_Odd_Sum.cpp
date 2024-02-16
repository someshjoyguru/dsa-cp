#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

/*
k=2
n-1-k
1 3 5 4 2
1 2 3 4 5 ->4
1 2 3 5 4 ->3
1 2 5 3 4 ->3

oeoe...k times ...baki <end_same>eoeoe...

4 12345
3 12354 
2 12435
1 13524

*/ 

void solve(){
    ll n,k;
    cin>>n>>k;
    for (ll i=1; i<=n; i++){
        if (i<k)cout<<i<<" ";
        else{
            ll j=i+1;
            for (;i<=n; i+=2)cout<<i<<" ";
            for (;j<=n; j+=2)cout<<j<<" ";
            cout<<endl;
            return;
        }
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