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
    sin(s)
        s = " " + s;
        vll pp(n+5, n);
        vll ss(n+5,0);
        for(int j=n; j>=1; j--){
            if(s[j]=='p') pp[j]=j;
            else pp[j]=pp[j+1];
        }
        for(int j=1; j<=n; j++){
            if(s[j]=='s') ss[j]=j;
            else ss[j]=ss[j-1];
        }
        debug(pp);
        debug(ss);
        vll v(n);
        for(int j=1; j<=n; j++){
            int u_p = INT32_MAX;
            if(pp[j]<=n){
                u_p = pp[j];
            }
            int u_s = INT32_MAX;
            if(ss[j]>=1){
                u_s = n - ss[j] +1;
            }
            if(u_p != INT32_MAX && u_s != INT32_MAX){
                v[j-1] = min(u_p, u_s);
            }
            else if(u_p != INT32_MAX){
                v[j-1] = u_p;
            }
            else if(u_s != INT32_MAX){
                v[j-1] = u_s;
            }
            else{
                v[j-1] = n;
            }
        }
        sort(v)
        bool fl=true;
        f(i,0,n) {
            if(v[i]<i+1){
                fl=false;
                break;
            }
        }
        if (fl)pYES
        else pNO
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}

        
