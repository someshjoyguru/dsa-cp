#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<ll> odd;
    vector<ll> even;
    for (ll i=0; i<n; i++){
        ll x;
        cin>>x;
        if (i%2)odd.push_back(x);
        else even.push_back(x);
    }
    set<ll> st;
    for (ll i=1; i<odd.size(); i++)odd[i]+=odd[i-1];
    for (ll i=1; i<even.size(); i++)even[i]+=even[i-1];
    ll i=0,j=0;
    while(i<odd.size() && j<even.size()){
        if (st.count(odd[i]-even[j])){
            cout<<"YES"<<endl;
            return;
        }else{
            st.insert(odd[i]-even[j]);
        }
        i++;j++;
    }
    cout<<"NO"<<endl;
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}