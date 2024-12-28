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

vll func(ll l, ll r, ll lim){ 
    cout<<l<<" "<<r<<endl;
    if(r - l + 1 < lim) return {0, 0};
    if(r - l + 1 == 1) return {l, 1}; 
    ll mid = l + (r - l) / 2; 
    if( (r - l + 1) % 2 ){ 
        vll res = func(l, mid - 1, lim); 
        cout<<l<<" "<<r<<endl;
        debug(res);
        return {mid + 2 * res[0] + mid * res[1], 2 * res[1] + 1}; 
    } 
    else{ 
        vll res = func(l, mid, lim); 
        cout<<l<<" "<<r<<endl;
        debug(res);
        return {2 * res[0] + mid * res[1], 2 * res[1]}; 
    }
} 

void solve() {
    in(n) in(k)
    auto x=func(1, n, k);
    debug(x);
    cout<<x[0]<<endl;
    cout<<endl;
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}