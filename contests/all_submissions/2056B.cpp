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
    vvll gp(n);
    vector<string> ggp;
    f(i,0,n){
        sin(s)
        ggp.push_back(s);
        f(j,0,n){
            if (s[j]=='1'){
                gp[j].push_back(i);
                gp[i].push_back(j);
            }
        }
    }
    vll ans(n,0);
    f(i,0,n)ans[i]=i;
    f(i,0,n-1){
        ll miniid=i;
        f(j,i+1,n){
            bool fl;
            if (ans[miniid]<ans[j]){
                fl=(ggp[ans[miniid]][ans[j]]=='0');
            }else fl=(ggp[ans[j]][ans[miniid]]=='1');
            if (fl) miniid=j;
        }
        if (miniid!=i) swap(ans[i],ans[miniid]);
    }
    // vvll v;
    // f(i,0,n){
    //     v.push_back({(ll)(gp[i].size()),i});
    // }
    // rsort(v)
    // ll cnt=n;
    // f(i,0,n){
    //     ans[v[i][1]]=cnt;
    //     cnt--;
    // }
    f(i,0,n){
        cout<<ans[i]+1<<" ";
    }
    cout<<endl;
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}