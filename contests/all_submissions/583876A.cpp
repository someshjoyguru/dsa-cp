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
    in(k)
    vin(v,k)
    vvll vv;
    // vv.push_back({2,k,1});
    // f(i,0,k)v[i]=v[i]%2;
    rf(i,k-1,0){
        if (v[i]>=i && (i==k-1 || v[i+1]>v[i])){}
        else {
            if (i==k-1 || v[i]<i){
                ll diff=i-v[i];
                vv.push_back({1,i+1,diff});
                f(j,0,i+1)v[j]=v[j]+diff;
            }else{
                vv.push_back({2,i+1,i+1});
                f(j,0,i+1)v[j]=v[j]%(i+1);
            }
        }   
    }
    debug(v)
    cout<<vv.size()<<endl;
    for(auto x:vv){
        cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
    }
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) solve();
}