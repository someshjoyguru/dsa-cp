#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<int> v(n);
    for (int i=0; i<n; i++)cin>>v[i];
    ll i=0; // start pointer - follows j and deletes the ele from the set
    ll j=0; // end pointer - goes first and finds the unique set
    ll maxi=0;
    set<ll> st;
    while(i<n && j<n){
        while (j<n && st.count(v[j])==0){
            st.insert(v[j]);
            maxi=max(maxi,j-i+1);
            j++;
        }
        while (j<n && st.count(v[j])!=0){
            st.erase(v[i]);
            i++;
        }
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