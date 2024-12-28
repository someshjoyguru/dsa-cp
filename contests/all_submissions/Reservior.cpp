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
#define pYES cout<<"yes\n";
#define pNO cout<<"no\n";
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
    in(n) in(m)
    // b-1, w-2, a-3
    vvll v(n);
    f(i,0,n){
        sin(s)
        f(j,0,m){
            if (s[j]=='B')v[i].push_back(1);
            else if (s[j]=='W')v[i].push_back(2);
            else v[i].push_back(3);
        }
    }
    f(i,0,n){
        f(j,0,m){
            if (i + 1 < n && v[i][j] == 1 && v[i + 1][j] != 1) {
                pNO
                return;
            }
            if (v[i][j] == 2) {
                if ((j + 1 < m && v[i][j + 1] == 3) || (j - 1 >= 0 && v[i][j - 1] == 3) || (i + 1 < n && v[i + 1][j] == 3)) {
                    pNO
                    return;
                }
                if (i == n - 1 || j == 0 || j == m - 1) {
                    pNO
                    return;
                }
            }
        }
    }
    pYES
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}