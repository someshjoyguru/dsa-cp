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

// Function to generate all divisors of x
vector<int> getDivisors(int x) {
    vector<int> divisors;
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
            divisors.push_back(i);
            if (i != x / i) divisors.push_back(x / i);
        }
    }
    return divisors;
}

// Recursive function to count arrays
int countArrays(int x, int n, const vector<int>& divisors, vector<vector<int>>& dp) {
    if (x == 1) return 1; // Base case: 1 product has only one representation
    if (n == 0) return 0; // No more arrays allowed

    if (dp[x][n] != -1) return dp[x][n];

    int count = 0;
    for (int divisor : divisors) {
        if (x % divisor == 0) {
            count += countArrays(x / divisor, n - 1, divisors, dp);
        }
    }
    dp[x][n] = count;
    return count;
}

void solve() {
    in(k) in(n)
    ll x=4;
    vector<int> divisors = getDivisors(x);

    // Initialize DP table
    vector<vector<int>> dp(x + 1, vector<int>(n + 1, -1));

    // Count arrays
    int result = countArrays(x, n, divisors, dp);
    cout << "Number of arrays: " << result << endl;
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}