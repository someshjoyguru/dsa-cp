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
    vvll v;
    f(i,0,n){
        in(l) in(r)
        v.push_back({l,r});
    }
    vvll e;
    vvll g(n);
    f(i,0,n-1){
        in(u) in(v)
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
        e.push_back({u,v});
    }
    vll a;
    f(i,0,n){
        if (v[i][0]==v[i][1])a.push_back(v[i][0]);
        else a.push_back(v[i][0]);
    }
    ll maxi=*max_element(all(a));
    f(i,0,n){
        if (maxi!=a[i]){
            if (maxi<=v[i][1]) a[i]=maxi;
            else a[i]=v[i][1];
        }
    }
    debug(a)
    // set<ll> st(all(a));
    // ll sum=accumulate(all(st),0ll);
    // debug(sum)
    // cout<<sum<<endl;
    // cout<<*max_element(all(a))<<endl;
    
    // tree seq

    ll x=-1;
    f(i,0,n) if (g[i].size()==1){
        x=i;
        break;
    }
    vll seq={x};
    ll par=-1;
    while(1){
        ll i=seq.back();
        auto vv=g[i];
        for (ll xx:vv) if (xx!=par)seq.push_back(xx);
        par=i;
        // debug(seq)
        ll ii=seq.back();
        // if (ii==i) break;
        if (g[ii].size()==1 && i!=x){
            break;
        }
    }
    map<ll,ll> mp;
    f(i,0,n)mp[seq[i]]=i;
    vvll ob;
    f(i,0,n){
        ob.push_back({seq[i],a[i]});
    }
    debug(seq)
    debug(ob)
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}