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

ll solve2(ll n, vll& a){
    ll seconds = 0;
    while (true) {
        bool stable = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] < a[i + 1]) {
                a[i] = a[i + 1];
                stable = false;
            }
        }
        if (stable) break;
        seconds++;
    }
    return seconds;
}

void generateTestCases(int T, int maxN, int maxValue) {
    cout << T << endl; // Print the number of test cases
    for (int t = 0; t < T; ++t) {
        int N = 1 + rand() % maxN; // Random size of the array (1 to maxN)
        cout << N << endl;
        for (int i = 0; i < N; ++i) {
            cout << 1 + rand() % maxValue << " "; // Random values (1 to maxValue)
        }
        cout << endl;
    }
}

void solve() {
    // in(n)
    ll maxN=100;
    ll maxValue=10;
    ll n=1 + rand() % maxN;
    vll v(n,0);
    f(i,0,maxN){
        v[i]=1 + rand() % maxValue;
    }
    // vin(v,n)
    ll maxi=(*max_element(all(v)));
    vll vv;
    f(i,0,n) if (v[i]==maxi)vv.push_back(i);
    ll mm=vv[0];
    f(i,1,vv.size())mm=max(mm,vv[i]-vv[i-1]-1);

    // auto mm = max_element(all(v));
    // auto mn = min_element(v.begin(),mm);
    
    if (mm!=solve2(n,v)){
        debug(v);
    }
    // cout<<mm<<endl;
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}