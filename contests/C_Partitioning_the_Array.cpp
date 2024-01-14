#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for (ll i=0; i<n; i++)cin>>v[i];
    ll ans=1;
    set<ll> st;
    for (int i = 1; i < (int) sqrt(n) + 1; i++) { 
        if (n % i == 0){
            st.insert(i);
            st.insert(n/i);
        }
    }
    for (auto i : st){
        cout<<i<<" ";
    }
    cout<<endl;
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