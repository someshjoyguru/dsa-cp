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
    vin(v,n)
    ll sum=accumulate(all(v),0ll);
    if (sum==0){
        cout<<"0\n";
        return;
    }
    ll i=0, j=n-1;
    while(i<n && v[i]==0)i++;
    while(j>=0 && v[j]==0 && i<j)j--;
    debug(i);
    debug(j);
    bool fff=false;
    f(x,i,j+1){
        if (v[x]==0){
            fff=true;
            break;
        }
    }
    if (fff){
        cout<<"2\n";
    }else cout<<"1\n";

    // bool fl=true;
    // f(i,0,n){
    //     if (v[i]==0) {
    //         fl=false;
    //         break;
    //     }
    // }
    // if (fl){
    //     cout<<"1\n";
    //     return;
    // }
    // if (v[0]!=0 && v[n-1]!=0){
    //     cout<<"2\n";
    //     return;
    // }else if (v[0]==0 && v[n-1]==0){
    //     bool ff=false;
    //     f(i,1,n-1){
    //         if (v[i]==0) {
    //             ff=true;
    //             break;
    //         }
    //     }
    //     cout<<"2\n";
    //     return;
    // }else{
    //     cout<<"1\n";
    //     return;
    // }

}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}