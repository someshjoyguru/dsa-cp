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

ll calc(ll k, vll& v){
    ll c=v[k];
    ll maxi=v[0];
    ll ans=0;
    f(i,1,v.size()){
        maxi=max(maxi,v[i]);
        if (maxi==c) ans++;
        else if (maxi>c)break;
    }
    return ans;
}

void solve() {
    in(n) in(k)
    vin(v,n)
    k--;
    ll id=-1;
    f(i,0,n){
        if (v[k]<v[i]){
            id=i;
            break;
        }
    }
    if (id==-1){
        cout<<n-1<<endl;
    }else{
        ll c1=calc(k,v);
        debug(c1);
        swap(v[k],v[id]);
        ll c2=calc(id,v);
        debug(c2);
        swap(v[k],v[id]);
        swap(v[k],v[0]);
        ll c3=calc(0,v);
        debug(c3);
        cout<<max({c1,c2,c3})<<endl;
    }
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}