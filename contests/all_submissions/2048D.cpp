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
    in(n) in(m)
    vin(a,n)
    vin(b,m)
    ll kk=a[0];
    sort(a) sort(b)
    ll original_rank = n-(upper_bound(a.begin(), a.end(), kk) - a.begin())+1;
    debug(original_rank);
    f(k,1,m+1){
        ll sum=0;
        ll p=(m/k)*k;
        debug(p);
        multiset<ll> st(all(b));
        f(i,0,m/k){
            multiset<ll> gp;
            f(j,0,k){
                if (*st.begin()<=kk){
                    gp.insert(*st.begin());
                    st.erase(st.begin());
                }else{
                    gp.insert(*(--st.end()));
                    st.erase(--st.end());
                }
            }
            ll hard = *(--gp.end());
            debug(hard);
            if (hard<=kk) sum++;
            else {
                ll just_hard = (*upper_bound(all(gp),kk));
                ll cannot_solve_count=(lower_bound(all(a),just_hard)-a.begin());
                ll rank= 1+n-cannot_solve_count;
                sum+=rank;
                debug(just_hard);
                debug(cannot_solve_count);
                debug(rank);
            }
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}