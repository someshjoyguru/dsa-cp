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
    in(n) in(k)
    if (n==1){
        if (k==1)cout<<1<<endl;
        else cout<<-1<<endl;
        return;
    }
    ll sp=0;
    f(i,1,n+1)sp+=(i)*(n-i+1);
    ll nf=1;
    bool fl=false;
    f(i,2,n+1){
        nf=nf*2;
        if (nf>=k){
            fl=true;
            break;
        }
    }
    if (!fl)cout<<-1<<endl;
    else {
        vll v;
        f(i,1,n+1)v.push_back(i);
        ll sp=0;
        f(i,1,n+1)sp+=(i)*(n-i+1);

        // f(i,0,n){
        //     ll mini=v[i];
        //     f(j,i,n){
        //         mini=min(mini,v[i]);
        //         cout<<mini<<" ";
        //     }
        //     cout<<endl;
        // }
        vll v1=v;
        f(i,0,n)cout<<v[i]<<" ";
        cout<<endl;
        reverse(all(v1));
        ll ccc=1;
        while(v!=v1){
            next_permutation(all(v));
            ll cc=0;
            
            f(i,0,n){
                ll mini=v[i];
                f(j,i,n){
                    mini=min(mini,v[j]);
                    cc+=mini;
                }
            }
            if (sp==cc){
                f(i,0,n)cout<<v[i]<<" ";
                cout<<endl;
                ccc++;
            }
        }
        cout<<ccc<<endl;
    }
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}