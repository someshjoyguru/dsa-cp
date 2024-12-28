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

/*
ing msk = string(n,'1');
    f(i,0,n){
        if (s[i]==msk[i]) msk[i]='0';
    }
    debug(msk);
    
    ll i=0;
    while(i<n && msk[i]=='0')i++;
    msk=msk.substr(i);
    debug(msk);
*/

void solve() {
    sin(s)
    ll n=s.size();
    ll i=0;
    while(i<n && s[i]=='1')i++;
    if (i==n){
        cout<<1<<" "<<1<<" "<<1<<" "<<n<<endl;
        return;
    }
    ll len=n-i;
    ll maxid=-1;
    ll maxi=0;
    f(i,0,n-len+1){
        string ss=s.substr(i,len);
        string sss=s.substr(n-len);
        ll j=0;
        while(j<len && (ss[j]-'0')^(sss[j]-'0')==1)j++;
        if (maxi<j){
            maxi=j;
            maxid=i;
        }
        // debug(sss);
        // debug(maxid);
        // debug(maxi);
    }
    cout<<maxid+1<<" "<<maxid+len<<" "<<1<<" "<<n<<endl;
    // l1 r1 l2 r2
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}