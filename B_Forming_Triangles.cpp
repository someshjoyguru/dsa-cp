#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    int n;
    cin >> n;
    
    vector<int> a(n), cnt(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    
    long long ans = 0;
    int smaller = 0;
    
    for (int i = 0; i <= n; i++) {
        // equilateral
        ans += 1LL * cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
        // isosceles
        ans += 1LL * cnt[i] * (cnt[i] - 1) / 2 * smaller;
        smaller += cnt[i];
    }
    
    cout << ans << endl;
}

int main(){
    fastio()
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}