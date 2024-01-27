#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long


void solve(){
    ll x, n;
    cin >> x >> n;
    ll k = x/n;
    set<ll> st;

    for (ll i = 1; i <= sqrt(x); i++){
        if (x % i == 0){
            st.insert(i);
            st.insert(x / i);
        }
    }
    ll temp=*st.begin();
    for (auto i : st){
        if (i>k){
            cout<<temp<<endl;
            return;
        }
        if (i==k){
            cout<<i<<endl;
            return;
        }
        temp=i;
    }
    cout<<temp<<endl;
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