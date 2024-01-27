#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n;
    cin >> n;

    vector<ll> a(n), d(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n; i++) cin >> d[i];

    vector<ll> l(n), r(n);
    for (ll i = 0; i < n; i++) {
        l[i] = i - 1;
        r[i] = i + 1;
    }

    vector<ll> ans(n);
    vector<ll> monsters(n);
    iota(monsters.begin(), monsters.end(), 0);

    for (ll i = 0; i < n; i++) {
        set<ll> die;
        for (ll x : monsters) {
            ll damage = 0;
            if (l[x] != -1) damage += a[l[x]];
            if (r[x] != n) damage += a[r[x]];
            if (damage > d[x]) die.insert(x);
        }

        monsters.clear();
        ans[i] = die.size();

        for (ll x : die) {
            if (l[x] != -1) {
                r[l[x]] = r[x];
                if (die.find(l[x]) == die.end()) monsters.push_back(l[x]);
            }
            if (r[x] != n) {
                l[r[x]] = l[x];
                if (die.find(r[x]) == die.end()) monsters.push_back(r[x]);
            }
        }
    }

    for (ll x : ans) cout << x << " ";
    cout << endl;

}

/*
d->4 9 1 18 1 -> defence
a->3 4 7 5 10 -> damage karne ka power
3 x x 5 x
x x x 5 x
*/
int main(){
    fastio()
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}