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

// union-find template
class UnionFind {
    vector<int> id, size;
    int cnt;
public:
    UnionFind(int n) : id(n), size(n, 1), cnt(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        id[x] = y;
        size[y] += size[x];
        --cnt;
    }
    int getSize(int a) {
        return size[find(a)];
    }
    int getCount() { return cnt; }
};

void solve() {
    in(n) in(m1) in(m2)
    vvll fg(n), gg(n);
    vvll e;
    f(i,0,m1){
        in(u) in(v)
        u--; v--;
        e.push_back({u,v});
        fg[u].push_back(v);
        fg[v].push_back(u);
    }
    UnionFind dsugg(n), dsufg(n);
    f(i,0,m2){
        in(u) in(v)
        u--; v--;
        dsugg.connect(u,v);
        gg[u].push_back(v);
        gg[v].push_back(u);
    }
    ll c=0;
    for(auto it:e){
        if (dsugg.find(it[0])==dsugg.find(it[1])){
            dsufg.connect(it[0],it[1]);
        }else c++;
    }
    c+=(dsufg.getCount()-dsugg.getCount());
    cout<<c<<endl;
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}