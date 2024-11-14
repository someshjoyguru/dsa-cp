#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve() {
    ll n;
    cin >> n;
    
    vector<pair<ll, ll>> intervals(n);
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    
    pair<ll, ll> p1 = {-100, 100}, p2 = {-100, 100};

    for (const auto& interval : intervals) {
        ll a = interval.first, b = interval.second;

        if (max(a, p1.first) <= min(b, p1.second)) {
            p1.first = max(a, p1.first);
            p1.second = min(b, p1.second);
        } else if (max(a, p2.first) <= min(b, p2.second)) {
            p2.first = max(a, p2.first);
            p2.second = min(b, p2.second);
        } else {
            cout << -1 << endl;
            return;
        }
    }

    ll T1 = p1.first, T2 = p2.first;
    if (T1 > T2) swap(T1, T2);

    cout << T1 << " " << T2 << endl;
}

int main() {
    fast;
    int t = 1;
    while (t--) solve();
}
