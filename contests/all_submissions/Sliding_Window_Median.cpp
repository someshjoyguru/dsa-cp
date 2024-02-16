#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

/*Ordered set template */
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
// ends here

void solve(){
    ordered_set<pair<ll,ll>> st;
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for (ll i=0; i<n; i++)cin>>v[i];
    for (ll i=0; i<k; i++)st.insert({v[i],i});
    cout<<st.find_by_order((k-1)/2)->first<<" ";
    for (ll i=1; i<n-k+1; i++){
        st.erase({v[i-1],i-1});
        st.insert({v[i+k-1],i+k-1});
        cout<<st.find_by_order((k-1)/2)->first<<" ";
    }
}

void solve2(){
    
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