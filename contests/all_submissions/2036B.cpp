#include <bits/stdc++.h>
using namespace std;

#define int   long long
#define lld   long double
#define gcd   __gcd
#define pb    push_back
#define ppb   pop_back
#define pf    push_front
#define ump   unordered_map
#define pairs  pair<int,int>
#define V(el)  vector<el>
#define V1D   vector<int>
#define V2D   vector<vector<int>>
#define L_B   lower_bound
#define U_B   upper_bound
#define P_Q   priority_queue
#define cin(n)  int n;cin>>n;
#define F(el)  el.first
#define S(el)  el.second
#define nl  '\n'
#define rtn return
#define brk break
#define cntn continue
#define pys cout<<"YES\n"
#define pno cout<<"NO\n"
#define pms cout<<-1<<nl
#define sz(el) (int)el.size()
#define ckmax(el,ell) el=max(el,ell)
#define ckmin(el,ell) el=min(el,ell)

#define LETSGO int TESTCASES;cin>>TESTCASES;while(TESTCASES--)
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rf(a,b,c) for(int a=c-1;a>=b;a--)
#define setbit(x) __builtin_popcount(x)
#define clz(x) __builtin_clz(x)
#define ctz(x) __builtin_ctz(x)
#define all(el) el.begin(),el.end()
#define rall(el) el.rbegin(),el.rend()
#define sumALL(el) accumulate(all(el),0ll)
#define minALL(el) *min_element(all(el))
#define maxALL(el) *max_element(all(el))
#define BOOM ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pinf LLONG_MAX
#define ninf LLONG_MIN

// #ifndef ONLINE_JUDGE
// #include "debug.h"
// #else
// #define debug(...) 42
// #endif


void printans(std::vector<int>&a)
{
	int N = a.size();
	for (int i = 0; i < N; i++)
		cout << a[i] << " \n"[i == N - 1];
	return;
}

int n;
vector<int>a;

void arrayInput()
{
	cin >> n;
	a.resize(n);
	fr(i, 0, n)
	cin >> a[i];
}



void solveTestCases()
{
	cin(n)cin(k)
	V1D v(k + 5);
	fr(i, 0, k) {
		cin(b)cin(c)
		v[b] += c;
	}
	sort(rall(v));
	int ans = 0;
	fr(i, 0, n) {
		if (i > k)break;
		ans += v[i];
	}
	cout << ans << nl;
	return;
}

int32_t main() {
	BOOM
// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// freopen("error.txt", "w", stderr);
// #endif

	LETSGO
	solveTestCases ();


	return 0;
}