#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


void solve(){
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<map<array<int,2>, vector<int>>> mp(3);
    for (int i = 0; i < n - 2; i++) {
        mp[0][{a[i], a[i + 1]}].push_back(a[i + 2]);
        mp[1][{a[i], a[i + 2]}].push_back(a[i + 1]);
        mp[2][{a[i + 1], a[i + 2]}].push_back(a[i]);
    }

    long long ans = 0;

    for (int i = 0; i < 3; i++) {
        for (auto &[key, v] : mp[i]) {
            sort(v.begin(), v.end());
            long long curr = 0;
            map<int,int> ct;
            int m = v.size();
            for (int j : v) ct[j]++;
            for (int j : v) {
                curr += (m - ct[j]);
            }
            ans += curr / 2;
        }
    }

    cout << ans << endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}