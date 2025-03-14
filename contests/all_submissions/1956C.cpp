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
    ll x=1;
    ll ops=n;
    ll s=0,ss=(n*(n+1))/2;
    while(x*n<=ss)x++;
    // ops+=(x-1);
    // s+=(x-1)*ss;
    vvll v(n,vll(n,0));
    f(i,0,n){
        f(j,0,n){
            v[i][j]=j+1;
        }
    }
    f(j,0,x){
        f(i,0,n){
            v[i][j]=i+1;
        }
    }
    f(i,0,n-x+1){
        f(j,0,n){
            v[i][j]=j+1;
        }
    }
    s=0;
    f(i,0,n)f(j,0,n)s+=v[i][j];
    // f(i,x,n+1)s+=n*i;
    // f(i,0,n-x+1){
    //     s+=((x-1)*(x))/2;
    // }
    // f(i,n-x+1,n+1)s+=(i*(x-1));
    
    cout<<s<<" "<<2*n<<endl;
    f(i,1,n+1){
        cout<<1<<" "<<i<<" ";
        f(j,1,n+1)cout<<j<<" ";
        cout<<endl;
    }
    f(i,1,x){
        cout<<2<<" "<<i<<" ";
        f(j,1,n+1)cout<<j<<" ";
        cout<<endl;
    }
    f(i,1,n-x+2){
        cout<<1<<" "<<i<<" ";
        f(j,1,n+1)cout<<j<<" ";
        cout<<endl;
    }
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}