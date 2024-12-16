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

class SegmentTree {
private:
    vector<ll> arr;       // Original array
    vector<ll> tree;      // Segment tree to store indices
    ll n;

    // Function to build the segment tree
    void buildTree(ll node, ll start, ll end) {
        if (start == end) {
            // Leaf node, store the index
            tree[node] = start;
        } else {
            ll mid = (start + end) / 2;
            ll leftChild = 2 * node + 1;
            ll rightChild = 2 * node + 2;

            buildTree(leftChild, start, mid);
            buildTree(rightChild, mid + 1, end);

            // Store the index of the minimum value
            ll leftIdx = tree[leftChild];
            ll rightIdx = tree[rightChild];
            tree[node] = (arr[leftIdx] <= arr[rightIdx]) ? leftIdx : rightIdx;
        }
    }

    // Function to handle range queries
    ll queryTree(ll node, ll start, ll end, ll l, ll r) {
        if (r < start || end < l) {
            // Out of range
            return -1;
        }
        if (l <= start && end <= r) {
            // Fully in range
            return tree[node];
        }

        ll mid = (start + end) / 2;
        ll leftChild = 2 * node + 1;
        ll rightChild = 2 * node + 2;

        ll leftIdx = queryTree(leftChild, start, mid, l, r);
        ll rightIdx = queryTree(rightChild, mid + 1, end, l, r);

        if (leftIdx == -1) return rightIdx;
        if (rightIdx == -1) return leftIdx;

        return (arr[leftIdx] <= arr[rightIdx]) ? leftIdx : rightIdx;
    }

    // Function to update the segment tree
    void updateTree(ll node, ll start, ll end, ll idx, ll value) {
        if (start == end) {
            // Update leaf node
            arr[start] = value;
            tree[node] = start;
        } else {
            ll mid = (start + end) / 2;
            ll leftChild = 2 * node + 1;
            ll rightChild = 2 * node + 2;

            if (idx <= mid) {
                updateTree(leftChild, start, mid, idx, value);
            } else {
                updateTree(rightChild, mid + 1, end, idx, value);
            }

            // Update the current node
            ll leftIdx = tree[leftChild];
            ll rightIdx = tree[rightChild];
            tree[node] = (arr[leftIdx] <= arr[rightIdx]) ? leftIdx : rightIdx;
        }
    }

public:
    SegmentTree(const vector<ll>& input) {
        arr = input;
        n = arr.size();
        tree.resize(4 * n);
        buildTree(0, 0, n - 1);
    }

    ll query(ll l, ll r) {
        return queryTree(0, 0, n - 1, l, r);
    }

    void update(ll idx, ll value) {
        updateTree(0, 0, n - 1, idx, value);
    }
};

void solve() {
    in(n) in(d) in(k)
    vll v(n+2,0);
    while(k--){
        in(l) in(r)
        l--; r--;
        v[l]++;
        v[r+1]--;
    }
    f(i,1,n+1)v[i]+=v[i-1];
    SegmentTree sg(v);
    ll mini=LLONG_MAX;
    ll maxi=0;
    ll minId=0, maxId=0;
    f(i,0,n-d+1){
        ll tmp = sg.query(i,i+d-1);
        if (v[tmp]<mini){
            mini=min(mini,v[tmp]);
            minId=i+1;
        }
        if (v[tmp]>maxi){
            maxi=max(maxi,v[tmp]);
            maxId=i+1;
        }
        debug(tmp);
        debug(maxi);
        debug(mini);
        debug(minId);
        debug(maxId);

    }
    cout<<maxId<<" "<<minId<<endl;
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}