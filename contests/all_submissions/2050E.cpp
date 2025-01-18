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

void rec() {
    sin(a) sin(b) sin(c)
    ll n=a.size(), m=b.size();
    auto func=[&](ll i, ll j, ll k, auto func)->ll{
        ll x=1e9;
        if (k==n+m) x=0;
        if (i<n) x=min(x,(a[i]!=c[k])+func(i+1,j,k+1,func));
        if (j<m) x=min(x,(b[j]!=c[k])+func(i,j+1,k+1,func));
        return x;
    };
    cout<<func(0,0,0,func)<<endl;
}

void solve() {
    sin(a) sin(b) sin(c)
    ll n=a.size(), m=b.size();
    vvll dp(n+10, vll(m+10, -1));
    auto func=[&](ll i, ll j, ll k, auto func)->ll{
        if (k==n+m) return dp[i][j]=0;
        if (dp[i][j]!=-1) return dp[i][j];
        else dp[i][j]=1e9;
        if (i<n) dp[i][j]=min(dp[i][j],(a[i]!=c[k])+func(i+1,j,k+1,func));
        if (j<m) dp[i][j]=min(dp[i][j],(b[j]!=c[k])+func(i,j+1,k+1,func));
        return dp[i][j];
    };
    cout<<func(0,0,0,func)<<endl;
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}