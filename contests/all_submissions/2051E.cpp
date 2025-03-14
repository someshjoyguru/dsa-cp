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


void solve() {
    in(n) in(k)
    vin(a,n)
    vin(b,n)
    vvll v;
    f(i,0,n)v.push_back({a[i],b[i]});
    sort(v)
    multiset<ll> st;
    ll p=v[0][0];
    ll maxi=0;
    f(i,0,n){
        ll tmp=v[i][0]*(n-i);
        auto it=lower_bound(all(st),v[i][0]);
        ll x=min(k,distance(it,st.end()));
        tmp+=(x*i);
        maxi=max(maxi,tmp);
        st.insert(v[i][1]);
    }
    f(i,0,n)swap(v[i][0],v[i][1]);
    sort(v)
    debug(v)
    st.clear();
    f(i,0,n)st.insert(a[i]);
    f(i,0,n){
        auto it=lower_bound(all(st),v[i][0]);
        it--;
        ll tmp=v[i][0]*(distance(it,st.end()));
        tmp+=min(k,(distance(it,st.begin())));

    }

    cout<<maxi<<endl;
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}