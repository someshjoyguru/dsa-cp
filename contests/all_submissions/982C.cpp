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
    vll g[n+1];
    f(i,0,n-1){
        in(u) in(v)
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (n%2){
        cout<<-1;
        return;
    }
    
    vll sz(n+1,0);
    function<ll(ll, ll)> dfs = [&](ll node, ll par) -> ll {
        ll sum = 0;
        for (ll ch : g[node]) {
            if (ch != par) {
                sum += (1 + dfs(ch, node));
            }
        }
        sz[node] = 1+sum;
        return sum;
    };
    sz[1]=dfs(1,-1);
    dfs(1,-1);
    debug(sz);
    ll cnt=0;
    f(i,2,n+1){
        if (sz[i]%2==0)cnt++;
    }
    cout<<cnt;
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) solve();
}