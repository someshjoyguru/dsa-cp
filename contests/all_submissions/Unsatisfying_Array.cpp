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
	vector<set<ll>> dp(n + 1);
	f(i,1,n+1){
		f(j,1,n+1){
			dp[i].insert(j);
		}
	}

	f(i,1,n+1){
		debug(i);
		debug(dp[i]);
	}
	vvll v(k);
	for (int i = 0; i < k; ++i) {
		in(l) in(r) in(m)
		v[i] = {l, r, m};
	}
	for (auto it: v){
		f(i,it[0], it[1]+1){
			dp[i].erase(it[2]);
		}
	}

	f(i,1,n+1){
		debug(i);
		debug(dp[i]);
	}
	vll ans(n + 1, 0);
	bool fl = true;
	f(i,1,n+1){
		if (dp[i].empty()) {
			fl = false;
			break;
		}
		ans[i] = *dp[i].begin();
	}

	if (!fl) {
		cout << -1 << "\n";
	} else {
		f(i,1,n+1){
			cout << ans[i] << " ";
		}
		cout << "\n";
	}	
}

int main() {
	fast;
	int t = 1;
	cin >> t;
	while(t--) solve();
}
