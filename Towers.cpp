#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);

    for (int i=0; i<n; i++)cin>>v[i];
    multiset<ll> st;
    // ll maxi = 0;
    for (int i=0; i<n; i++){
        // for (auto k : st){
        //     cout<<k<<" ";
        // }
        // maxi=max(maxi,(ll)st.size());
        // cout<<endl;
        if (st.size()==0){
            st.insert(v[i]);
            continue;
        }
        // auto it = upper_bound(st.begin(),st.end(),v[i]);
        // the above is generic upper_bound and gives tle
        auto it = st.upper_bound(v[i]);
        // but the above one is specific member function of multiset 
        // hence do not give tle
        if (it==st.end()){
            st.insert(v[i]);
        }else{
            st.insert(v[i]);
            st.erase(it);
        }
    }
    // maxi=max(maxi,(ll)st.size());
    cout<<st.size();
}

int main(){
    fastio()
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}