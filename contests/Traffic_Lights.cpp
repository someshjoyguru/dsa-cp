#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll x,n;
    cin>>x>>n;
    vector<ll> v(n);
    for (int i=0; i<n; i++)cin>>v[i];
    set<ll> st;
    multiset<ll> mst;
    st.insert(0);
    st.insert(x);
    mst.insert(x-0);
    for (int i=0; i<n; i++){
        st.insert(v[i]);
        auto it = st.find(v[i]);
        ll previ= (*it)-(*prev(it));
        ll nexti= (*next(it))-(*it);
        ll dele = (*next(it))-(*prev(it));
        auto mit= mst.find(dele);
        mst.erase(mit);
        mst.insert(previ);
        mst.insert(nexti);
        cout<<*mst.rbegin()<<" ";
    }
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