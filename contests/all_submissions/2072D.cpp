#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cerr.rdbuf(cout.rdbuf());
#define f(i,a,b) for (ll (i)=(a); (i)<(b); (i)++)
#define rf(i,a,b) for (ll (i)=(a); (i)>=(b); (i)--)
#define vll vector<ll>
#define vvll vector<vll>
#define in(n) ll n; cin>>n;
#define sin(s) string (s); cin>>(s);
#define vin(v,n) vll (v)(n); f(i,0,n)cin>>(v)[i];
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sort(v) sort(all(v));
#define rsort(v) sort(v) reverse(all(v));
#define pYES cout<<"YES\n";
#define pNO cout<<"NO\n";
const ll mod = 1000000007;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

template <typename T>
void _print(T x) { cerr << x; }
template <typename T, typename V>
void _print(pair<T, V> p) { cerr << "{"; _print(p.first); cerr << ", "; _print(p.second); cerr << "}"; }
template <typename T>
void _print(vector<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <typename T>
void _print(set<T> s) { cerr << "{ "; for (T i : s) { _print(i); cerr << " "; } cerr << "}"; }
template <typename T, typename V>
void _print(map<T, V> m) { cerr << "{ "; for (auto i : m) { _print(i); cerr << " "; } cerr << "}"; }
/* *********************Template ends here************** */

/*Ordered set template */
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
// ends here

void solve() {
    in(n)
    vin(v,n)
    ordered_set<ll> st;
    ll ll2=-1, ll2v=-1;
    rf(i,n-1,0){
        ll x=st.order_of_key(v[i]);
        st.insert(v[i]);
        if (ll2v<=x){
            ll2=i;
            ll2v=x;
        }
        debug(x);
    }
    st.clear();
    ll val=v[ll2];
    
    vll vv;
    f(i,0,ll2)vv.push_back(v[i]);
    f(i,ll2+1,n)vv.push_back(v[i]);

    vll leftg4(n,0);
    vll rightl4(n,0);
    
    f(i,1,n){
        if (vv[i-1]>val) leftg4[i-1]++;
    }
    rf(i,n-2,0){
        if (vv[i+1]>)
    }
    ll ll1=-1, ll1v=-1;
    rf(i,n-1,0){
        ll x=i-st.order_of_key(v[i]);
        st.insert(v[i]);
        if (ll1v<=x){
            ll1=i;
            ll1v=x;
        }
        debug(x);
    }
    
    cout<<ll2+1<<" "<<ll1+1<<endl;
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}