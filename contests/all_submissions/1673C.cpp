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
const ll MOD = 1e9+7;

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
const int N = 40004, M = 502;
long long dp[N][M];

// Referred author's solution
int reverse(int n)
{
    int r=0;
    while(n>0)
    {
        r=r*10+n%10;
        n/=10;
    }
    return r;
}

bool palindrome(int n)
{
    return (reverse(n)==n); 
}

void solve() {
    in(n)
    cout<<dp[n][M-1]<<endl;
}

int main() {
    fast;
    vector<int> palin;
    palin.push_back(0);
    for(int i=1;i<2*N;i++)
    {
        if(palindrome(i))
            palin.push_back(i);
    }
    debug(palin.size());
    for(int j=1;j<M;j++)
        dp[0][j]=1;
    for(int i=1;i<N;i++)
    {
        dp[i][0]=0;
        for(int j=1;j<M;j++)
        {
            if(palin[j]<=i)
                dp[i][j]=(dp[i][j-1]+dp[i-palin[j]][j])%MOD;
            else
                dp[i][j]=dp[i][j-1];
        }
    }
    int t = 1;
    cin >> t;
    while(t--) solve();
}