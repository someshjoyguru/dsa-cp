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

vll fix(5e5, 0);

void solve() {
    in(n)
    vvll v;
    f(i,0,n){
        in(x) in(y)
        v.push_back({x,y});
    }

    map<ll,ll> mp;
    for (auto p : v) {
        if (p[0] == p[1]) mp[p[0]]++;
    }
    debug(mp);
    vll vv;
    for (auto it: mp) {
        vv.push_back(it.first);
        fix[it.first] += it.second;
    }
    sort(vv)
    debug(vv);
    string s = "";
    f(i,0,n){
        ll l = v[i][0];
        ll r = v[i][1];
        if (l < r) {
            int g = upper_bound(all(vv), r) - lower_bound(all(vv), l);
            if (g < r-l+1) s += '1'; else s += '0';
        } else {
            if (fix[l] <= 1) s += '1'; else s += '0';
        }
    }
    cout << s << endl;
    for (auto it: mp) {
        fix[it.first] -= it.second;
    }
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}