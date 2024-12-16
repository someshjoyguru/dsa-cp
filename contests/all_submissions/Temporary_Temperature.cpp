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

bool fff(ll x, vll& a, ll k) {
    ll n = a.size();
    vll loww(n), upp(n);
    loww[0] = a[0] - x;
    upp[0] = a[0] + x;

    f(i,1,n) {
        ll nl = max(loww[i - 1], a[i] - x);
        ll nh = min(upp[i - 1], a[i] + x);

        if (nl > nh) {
            if (k > 0) {
                k--;
                loww[i] = a[i] - x;
                upp[i] = a[i] + x;
            } else {
                return false;
            }
        } else {
            loww[i] = nl;
            upp[i] = nh;
        }
    }
    return true;
}

void solve() {
    in(n) in(k)
    vin(a,n)

    ll l = 0, r = 1e9, ans = 1e9;
    while (l <= r) {
        ll md = (l + r) / 2;
        if (fff(md, a, k)) {
            ans = md;
            r = md - 1;
        } else {
            l = md + 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}


