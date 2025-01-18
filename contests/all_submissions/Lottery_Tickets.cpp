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
    in(n)
    vin(v,n)
    bool is1=false, is1e6=false;
    f(i,0,n){
        if (v[i]==1) is1=true;
        if (v[i]==1000000) is1e6=true;
    }
    ll x=v[0];
    if (!is1)v.push_back(1);
    if (!is1e6)v.push_back(1e6);
    sort(v)
    ll ans=1;
    auto ub=upper_bound(all(v),x);
    ub--;
    debug(*ub);
    ll i=ub-v.begin();
    debug(i);
    debug(v);
    if (i>0){
        if (v[i-1]==1){
            if (is1) ans+=(v[i]-v[i-1])/2;
            else ans+=(v[i]-1);
        }else ans+=(v[i]-v[i-1])/2;
    }
    debug(ans);
    n=v.size();
    if (i<n-1){
        if (v[i+1]==1000000){
            if (is1e6) ans+=(v[i+1]-v[i])/2;
            else ans+=(v[i+1]-v[i]);
            debug(ans);
        }else ans+=(v[i+1]-v[i])/2;
    }
    debug(ans);
    cout<<ans<<endl;
    return;
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}