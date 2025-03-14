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

//ref: editorial
void dfs(ll node, ll par, vector<set<ll>> &g, vll&p){
    p[node]=par;
    for(ll nei: g[node]){
        if(nei!=par){
            dfs(nei,node,g,p);
        }
    }
}
void solve() {
    in(n)
    vector<set<ll>> g(n);
    vll d(n,0);
    
    f(i,0,n-1){
        in(u) in(v)
        u--; v--;
        g[u].insert(v);
        g[v].insert(u);
        d[u]++; d[v]++;
    }

    vll p(n,-1);
    dfs(0,-1,g, p);

    vvll v;
    f(i,0,n)v.push_back({d[i],i});
    rsort(v)
    
    ll i1=v[0][1];
    ll i2=v[1][1];
    
    ll res=0;
    f(i,1,n){
        if (g[i1].count(v[i][1])){
            res=max(res,d[i1]+d[v[i][1]]-2);
        }else res=max(res,d[i1]+d[v[i][1]]-1);
    }

    f(i,2,n){
        if (g[i2].count(v[i][1])){
            res=max(res,d[i2]+d[v[i][1]]-2);
        }else res=max(res,d[i2]+d[v[i][1]]-1);
    }
    cout<<res<<endl;
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}