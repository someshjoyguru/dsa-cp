#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define  fastio() ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

void solve(){
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v;
    for (ll i = 0; i <n; i++) {
        ll x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    pbds st;
    ll ans = 0;
    for (int i = 0; i < v.size(); i++) {
        // auto it = s.lower_bound(v[i].second);
        ll ord=st.order_of_key(v[i].second);
        ans+=st.size()-ord;
        st.insert(v[i].second);
    }
    cout << ans << endl;
}

int main(){
    fastio();
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}