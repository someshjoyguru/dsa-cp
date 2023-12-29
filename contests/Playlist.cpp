#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for (ll i=0; i<n; i++)cin>>v[i];
    unordered_set<ll> st;
    ll maxi=0,temp=0;
    for (ll i=0; i<n; i++){
        if (st.find(v[i])==st.end()){
            st.insert(v[i]);
            temp++;
            maxi=max(temp,maxi);
        }else{
            temp=1;
            st.clear();
            st.insert(v[i]);
        }
        // cout<<maxi<<endl;
    }
    cout<<maxi;
}

int main(){
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}