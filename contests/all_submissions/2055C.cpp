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
// -5 2 3
// 0 0 0
// 3 1 0

    // if (s[0]=='D'){
    //     v[0][0]=-r[0];
    //     c[0]-=r[0];
    //     r[0]=0;
    // }
    // else {
    //     v[0][0]=-c[0];
    //     r[0]-=c[0];
    //     c[0]=0;
    // }
    
    // ll ii=0, jj=0;
    // f(i,0,n+m-3){
    //     if (s[i+1]=='R'){
    //         ii++;
    //         v[ii][jj]=-c[jj];
    //         r[ii]-=c[jj];
    //         c[jj]=0;
    //     }else {
    //         jj++;
    //         v[ii][jj]=-r[ii];
    //         c[jj]-=r[ii];
    //         r[ii]=0;
    //     }
    // }
void solve() {
    in(n) in(m)
    sin(s)
    vvll v;
    f(i,0,n){
        vin(vv,m)
        v.push_back(vv);
    }
    ll x=0;
    vll r(n,0), c(m,0);
    f(i,0,n){
        f(j,0,m){
            r[i]+=v[i][j];
            c[j]+=v[i][j];
        }
    }
    debug(v);
    ll ii=0, jj=0;
    v[ii][jj]=1e9;

    vll rc(n,0), cc(m,0);
    rc[0]++;
    cc[0]++;
    f(i,0,n+m-2){
        if (s[i]=='D'){
            ii++; v[ii][jj]=1e9;
        }else{
            jj++; v[ii][jj]=1e9;
        }
        rc[ii]++;
        cc[jj]++;
    }
    debug(r);
    debug(c);

    f(i,0,n){
        f(j,0,m){
            if (v[i][j]==1e9){
                if (rc[i]==1){
                    v[i][j]=-r[i];
                    c[j]-=r[i];
                    r[i]=0;
                    rc[i]--;
                    cc[j]--;
                }else{
                    v[i][j]=-c[j];
                    r[i]-=c[j];
                    c[j]=0;
                    rc[i]--;
                    cc[j]--;
                }
            }
        }
    }
    f(i,0,n){
        f(j,0,m){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}