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
const ll mod=1e9+7;

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



void solve(){
    sin(s)
    ll n=s.size();
    ll i=0;
    vvll v;
    while(i<n){
        ll st=i;
        vll tmp;
        while(i<n){
            ll a=0;
            while(i<n && s[i]=='a'){
                i++;
                a++;
            }
            if (a) tmp.push_back(a);
            bool fl=false;
            while(i<n && s[i]!='a'){
                if (s[i]=='b')fl=true;
                i++;
            }
            if (!fl) break;
        }
        // while(i<n && s[i]!='a' && s[i]!='b') i++;
        if (tmp.size()>0)v.push_back(tmp);
    }
    debug(v)
    ll ans=0;
    for (auto it: v){
        if (it.size()==1) ans=(ans+it[0])%mod;
        else{
            ll mul=it[0]+1;
            f(i,1,it.size()){
                mul=(((ll)mul*(it[i]+1))%mod+mod)%mod;
            }
            ans=(ans+mul-1+mod)%mod;
        }
    }

    // f(i,0,n){
    //     if (s[i]=='a')tmp++;
    //     else if (s[i]=='b') tmp1+=(tmp1==0)?tmp:tmp1*tmp;
    //     else {
    //         ans+=(tmp1*tmp);
    //         tmp1=0;
    //         tmp=0;
    //     }
    // }
    cout<<ans;
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) solve();
}