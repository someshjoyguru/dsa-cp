#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(i,a,b) for (ll (i)=(a); (i)<(b); (i)++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define sin(s) string (s); cin>>(s);
#define vin(v,n) vll (v)(n); f(i,0,n)cin>>(v)[i];
#define all(v) (v).rbegin(),(v).rend()
#define sort(v) sort(all(v));
#define pYES cout<<"YES"<<endl;
#define pNO cout<<"NO"<<endl;

void solve(){
    in(n) in(m) in(k)
    in(w)
    vin(a,w)
    vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= m - k; j++) {
            grid[i][j] += 1;
            if (i + k < n) grid[i + k][j] -= 1;
            if (j + k < m) grid[i][j + k] -= 1;
            if (i + k < n && j + k < m) grid[i + k][j + k] += 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0) grid[i][j] += grid[i - 1][j];
            if (j > 0) grid[i][j] += grid[i][j - 1];
            if (i > 0 && j > 0) grid[i][j] -= grid[i - 1][j - 1];
        }
    }

    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pq.push(grid[i][j]);
        }
    }
    sort(a);
    ll ans = 0;
    for (int i = 0; i < w; i++) {
        ans += pq.top() * a[i];
        pq.pop();
    }
    cout << ans << endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}