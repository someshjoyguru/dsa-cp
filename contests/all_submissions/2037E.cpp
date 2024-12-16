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

ll query(ll l, ll r){
    cout<<"? "<<l<<" "<<r<<endl;
    ll val;
    cin>>val;
    return val;
}

// reference: https://codeforces.com/contest/2037/submission/292072717
void solve() {
    in(n)
    if(n == 2)
    {
        ll ans = query(1, 2);
        if(ans == 1)
        {
            cout<<"! 01"<<endl;return;
        }
        else
        {
            cout<<"! IMPOSSIBLE"<<endl;return;
        }
    }
 
    string s1;
    vll ans;
    for(ll i = 2; i <= n; i++)
    {
        ll val = query(1,i);
        ans.push_back(val);
    }
 
    if(ans.back() == 0)
    {
        cout<<"! IMPOSSIBLE"<<endl;return;
    }
    ll j = -1;
    f(i,0,ans.size())
    {
        if(ans[i] > 0)
        {
            j = i;break;
        }
    }
    s1.push_back('1');
    f(i,0,ans[j])
    {
        s1.push_back('0');
    }
    while(s1.size() != j+2)
    {
        s1.push_back('1');
    }
    reverse(all(s1));
 
    for(ll i = j+1; i < ans.size(); i++)
    {
        if(ans[i] > ans[i-1])
        {
            s1.push_back('1');
        }
        else
        {
            s1.push_back('0');
        }
    }
 
    cout<<"! "<<s1<<endl;
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}