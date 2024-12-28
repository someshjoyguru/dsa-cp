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
    vll a(n);
    ll sp = -1;
    f(i,0,n) {
        cin >> a[i];
        if (a[i] != 1 && a[i] != -1 && sp == -1) {
            sp = i;
        }
    }

    set<ll> st;
    st.insert(0);

    vll pre1, suf1, pre2, suf2;
    ll sum = 0;

    
    rf(i,sp-1,0){
        sum += a[i];
        pre1.push_back(sum);
    }
    reverse(all(pre1));
    
    sum = 0;
    rf(i,n-1,sp+1){
        sum += a[i];
        pre2.push_back(sum);
    }
    reverse(all(pre2));

    sum = 0;
    if (sp != n - 1) {
        f(i,0,sp){
            sum += a[i];
            suf1.push_back(sum);
        }
    }
    sum = 0;
    if (sp != n - 1) {
        f(i,sp+1,n){
            sum += a[i];
            suf2.push_back(sum);
        }
    }
    debug(pre1);
    debug(suf1);
    debug(pre2);
    debug(suf2);
    for (ll psum : pre1) {
        st.insert(psum);
    }
    for (ll psum : pre2) {
        st.insert(psum);
    }
    for (ll ssum : suf1) {
        st.insert(ssum);
    }
    for (ll ssum : suf2) {
        st.insert(ssum);
    }

    if (sp != -1) {
        ll val = a[sp];
        
        for (ll psum : pre1) {
            st.insert(psum + val);
        }
        for (ll ssum : suf2) {
            st.insert(ssum + val);
        }
        st.insert(val);
    }
    ll cc=0;
    f(i,0,n){
        cc+=a[i];
        st.insert(cc);
        st.insert(a[i]);
    }
    cc=0;
    rf(i,n-1,0){
        cc+=a[i];
        st.insert(cc);
    }

    cout << st.size() << endl;
    for (ll x : st) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}
