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
// #define sort(v) sort(all(v));
// #define rsort(v) sort(v) reverse(all(v));
#define pYES cout<<"YES\n";
#define pNO cout<<"NO\n";

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

bool ff(vll &a, vll &b){
    if (a[1]!=b[1]) return a[1]<b[1];
    return a[0]>b[0];
}

void solve() {
    in(n)
    vvll v;
    f(i,0,n){
        in(x) in(y)
        v.push_back({x,y,i+1});
    }
    sort(all(v), ff);
    set<ll> st;
    map<ll,ll> mp;
    debug(v);
    f(i,0,n){
        if (st.empty()){
            st.insert(v[i][0]);
            mp[v[i][0]]=v[i][2];
        }else{
            auto lb=lower_bound(all(st),v[i][0]);
            if (lb!=st.end()){
                ll id = mp[(*lb)];
                cout<<id<<" "<<v[i][2];
                return;
            }
            if (mp.find(v[i][0])==mp.end()) {
                st.insert(v[i][0]);
                mp[v[i][0]]=v[i][2];
            }
        }
    }
    cout<<"-1 -1";
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) solve();
}