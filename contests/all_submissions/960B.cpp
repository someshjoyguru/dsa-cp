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
    in(n) in(k1) in(k2)
    vin(a,n)
    vin(b,n)
    vll e;
    f(i,0,n)e.push_back(abs(a[i]-b[i]));
    rsort(e)
    debug(e)
    ll tot=k1+k2;
    ll es = accumulate(all(e),0ll);
    if (tot>=es){
        ll x = tot-es;
        cout<<x%2;
        return;
    }

    ll lo=0, hi=0;
    f(i,0,n)hi=max(hi,e[i]);
    ll ans=hi;

    auto chk = [&](int md){
        ll sum=0;
        f(i,0,n) if(e[i]>md)sum+=(e[i]-md);
        return sum;
    };
    while(lo<=hi){
        ll md=lo+(hi-lo)/2;
        ll sum=chk(md);
        if (sum<=tot){
            ans=min(ans,md);
            hi=md-1;
        }else{
            lo=md+1;
        }
    }
    ll sum=chk(ans);
    ll left=tot-sum;
    f(i,0,n) if(e[i]>ans)e[i]=ans;
    priority_queue<ll> pq(all(e));
    while(left){
        ll tp=pq.top();
        pq.pop();
        tp--;
        pq.push(tp);
        left--;
    }
    ll f=0;
    while(pq.size()>0){
        ll tp=pq.top();
        pq.pop();
        f+=(tp*tp);
    }
    cout<<f;

    // ll sum=0;
    // f(i,0,n){
    //     if (sum+e[i]==tot){
    //         ll ans=0;
    //         f(j,i+1,n)ans+=(e[j]*e[j]);
    //         cout<<ans;
    //         return;
    //     }else if (sum+e[i]>tot){
    //         ll left=tot-sum;
    //         ll ans=0;
    //         f(j,i+1,n)ans+=(e[j]*e[j]);
    //         cout<<ans+((e[i]-left)*(e[i]-left));
    //         return;
    //     }
    //     sum+=e[i];
    // }
    // ll left=tot-sum;
    // if (left==0) cout<<0;
    // else {
    //     cout<<left%2;
    // }
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) solve();
}