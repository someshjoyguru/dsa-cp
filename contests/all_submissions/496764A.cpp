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

struct SegmentTree {
    vector<ll> arr;
    vector<pair<ll, ll>> tree; // (value, index)
    ll n;

    SegmentTree(vector<ll>& input) {
        arr = input;
        n = arr.size();
        tree.resize(4 * n, {INT_MAX, -1}); // Initialize tree with max values
        build(0, 0, n - 1);
    }

    void build(ll node, ll start, ll end) {
        if (start == end) {
            tree[node] = {arr[start], start};
        } else {
            ll mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void update(ll node, ll start, ll end, ll idx, ll value) {
        if (start == end) {
            arr[idx] = value;
            tree[node] = {value, idx};
        } else {
            ll mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    pair<ll, ll> query(ll node, ll start, ll end, ll l, ll r, ll x) {
        if (start > r || end < l) {
            return {INT_MAX, -1}; // Out of range
        }

        if (l <= start && end <= r) {
            if (tree[node].first >= x) {
                return {INT_MAX, -1}; // No value less than x in this segment
            }
            if (start == end) {
                return tree[node]; // Found a value less than x
            }
        }

        ll mid = (start + end) / 2;
        auto leftRes = query(2 * node + 1, start, mid, l, r, x);
        if (leftRes.first < x) {
            return leftRes; // If found in left, return immediately
        }
        return query(2 * node + 2, mid + 1, end, l, r, x); // Check right
    }

    void update(ll idx, ll value) {
        update(0, 0, n - 1, idx, value);
    }

    ll query(ll l, ll r, ll x) {
        auto result = query(0, 0, n - 1, l, r, x);
        return result.second; // Return index of the value less than x
    }
};

void solve() {
    in(n)
    vin(v,n)
    SegmentTree sg(v);

    in(q)
    while(q--){
        in(tt)
        if (tt==1){
            in(l) in(x)
            l--;
            sg.update(l,x);
        }else{
            in(l) in(r) in(x)
            l--; r--;

            ll id= sg.query(l, r, x);
            if (id==-1) cout<<-1<<endl;
            else cout<<id+1<<endl;
            // bool fl=true;
            // f(i,l,r+1){
            //     if (v[i]<=x){
            //         fl=false;
            //         cout<<i+1<<endl;
            //         break;
            //     }
            // }
            // if (fl) cout<<-1<<endl;
        }
    }
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}