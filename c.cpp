#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

int msb(int x) {
    int k = 0;
    while (x >>= 1) {
        k++;
    }
    return k;
}

int msb2(int x) {
    int q = msb(x);
    x = x ^ (1 << q); 
    int k = 0;
    if (x==0) return 1;
    while (x >>= 1) {
        k++;
    }

    return k + 1;
}

void solve(){
    // 110  010^100
    // 011  001^010
    ll n;cin>>n;
    cout<<msb2(n)<<endl;
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