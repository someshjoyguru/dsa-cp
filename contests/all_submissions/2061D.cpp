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
    in(n) in(m)
    vin(a,n)
    vin(b,m)
    multiset<ll> p(all(a)),q(all(b));
    ll diff=n-m;
    while(q.size()>0){
        auto itt=q.begin();
        auto it=p.find(*itt);
        if (it!=p.end()){
            p.erase(it);
            q.erase(itt);
        }else{
            if (diff==0 || *itt==1){
                pNO
                return;
            }else{
                ll x=*itt;
                q.erase(itt);
                ll xx=x/2, yy=x/2+x%2;
                if (xx!=0) q.insert(xx);
                if (yy!=0) q.insert(yy);
                if (q.size()>0) itt=q.begin();
                else break;
            }
        }
    }
    if (p.size()==0 && q.size()==0) pYES
    else pNO
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}