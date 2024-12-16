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

// #ifndef ONLINE_JUDGE
// #define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
// #else
// #define debug(x)
// #endif

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
    in(n) in(m) in(l);
    vvll hur(n, vll(2));
    f(i, 0, n) cin >> hur[i][0] >> hur[i][1];

    vector<pair<ll, ll>> vv;
    f(i, 0, m) {
        in(x) in(y)
        vv.push_back({x, y});
    }
    sort(vv);
    priority_queue<ll> pq;
    ll sum = 0, cnt = 0, id = 0;

    for (auto& hh : hur) {
        ll st = hh[0], en = hh[1];

        while (id < m && vv[id].first < st) {
            pq.push(vv[id].second);
            id++;
        }

        while (!pq.empty() && sum < en - st + 1) {
            sum += pq.top();
            cnt++;
            pq.pop();
        }

        if (sum < en - st + 1) {
            cout << -1 << endl;
            return;
        }
    }
    cout << cnt << endl;
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}