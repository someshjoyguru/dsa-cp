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
    vin(v, n);
    set<ll> st(all(v));

    if (st.size() == 1 && *st.begin() == 0) {
        cout << 0 << endl<<endl;
        return;
    }

    bool fl = true;
    ll p = *st.begin() % 2;
    for (ll x : st) {
        if (x % 2 != p) {
            fl = false;
            break;
        }
    }

    if (!fl) {
        cout << -1 << endl;
        return;
    }

    vll ans;
    ll op = 0;

    while (op < 40) {
        if (st.size() == 1 && *st.begin() == 0) {
            break;
        }

        auto it = st.rbegin();
        ll max1 = *it;
        st.erase(max1);

        if (st.empty()) {
            ans.push_back(max1);
            st.insert(0);
            break;
        }

        it = st.rbegin();
        ll max2 = *it;
        st.erase(max2);

        if ((max1 + max2) % 2 != 0) {
            cout << -1 << endl;
            return;
        }

        ll x = (max1 + max2) / 2;
        ans.push_back(x);

        set<ll> tmp;
        for (ll num : st) {
            tmp.insert(abs(num - x));
        }
        tmp.insert(abs(max1 - x));
        tmp.insert(abs(max2 - x));

        st = tmp;
        op++;
    }

    if (op == 40 && !(st.size() == 1 && *st.begin() == 0)) {
        cout << -1 << endl;
    } else {
        cout << ans.size() << endl;
        for (ll x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}