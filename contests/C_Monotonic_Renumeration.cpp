#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 998244353;
void solve(int tc = 0) {
    ll n;
	cin >> n;
    vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	map<ll, ll> last_pos;
	for (ll i = 0; i < n; i++) last_pos[a[i]] = i;
	
	ll group_end = 0, ngroups = 0;
	for (ll i = 0; i < n; i++) {
		group_end = max(group_end, last_pos[a[i]]);
		if (i == group_end) {
			++group_end;
			ngroups++;
		}
	}
	
	ll ans = 1;
	for (ll i = 0; i < ngroups - 1; i++) {
		ans = (ans * 2) % mod;
	}
	
	cout << ans << '\n';
}

int main(){
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}