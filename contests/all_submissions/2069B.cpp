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

ll dfs(ll i, ll j, ll c, vvll& v, vvll& vis) {
    if (i < 0 || j < 0 || i >= v.size() || j >= v[0].size() || v[i][j] != c || vis[i][j]==1)
        return 0;
    
    vis[i][j] = 1;
    ll cnt = 1;
    
    cnt += dfs(i + 1, j, c, v,vis);
    cnt += dfs(i - 1, j, c, v,vis);
    cnt += dfs(i, j + 1, c, v,vis);
    cnt += dfs(i, j - 1, c, v,vis);
    return cnt;
}


void solve() {
    in(n) in(m)
    vvll v;
    vvll vis(n,vll(m,0));
    f(i,0,n){
        sin(s)
        vll vv(m,0);
        f(i,0,m)if(s[i]=='X')vv[i]=1;
        v.push_back(vv);
    }
    ll ans=0;
    f(i,0,n){
        f(j,0,m){
            if ((i==0 || j==0 || i==n-1 || j==m-1) && !vis[i][j]){
                ans+=dfs(i,j,0,v,vis);
            }
        }
    }
    cout<<ans<<endl;
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}