#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(i,a,b) for (ll (i)=(a); (i)<(b); (i)++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define sin(s) string (s); cin>>(s);
#define vin(v,n) vll (v)(n); f(i,0,n)cin>>(v)[i];
#define all(v) (v).begin(),(v).end()
#define sort(v) sort(all(v));
#define pYES cout<<"YES"<<endl;
#define pNO cout<<"NO"<<endl;


void solve(){
    in(n)
    ll mini = INT_MAX;
    ll ind=-1;
    f(i,1,n+1) {
        in(x)
        if (mini > x) {
            mini = x;
            ind = i;
        }
    }
    vector<vll> arr(n + 1);
    f(i,0,n-1){
        in(x) in(y)
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    vll ans;
    vll dp(n + 1, 1);
    function<void(int, int)> dfs = [&](int u, int p) {
        int cnt = 0;
        for (int it : arr[u]) {
            if (it != p) {
                dfs(it, u);
                if (dp[it] == 1) cnt++;
            }
        }
        if (cnt == 0) {
            ans.push_back(u);
            dp[u] = 0;
        }
    };
    dfs(ind, 0);
    ll rst = ans.size();
    cout << rst - 1 << endl;
    f(i,0,rst-1)cout << ans[i] << " ";
    cout<<endl;
}



int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}