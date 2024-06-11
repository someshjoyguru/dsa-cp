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
    vin(A,n)
    ll ans=0;
    vll dp(n, 0);
    deque<pair<long long, int>> dq;

    for (int i = n - 2; i >= 0; --i) {
        while (!dq.empty() && dq.back().first <= dp[i + 1] + A[i + 1]) {
            dq.pop_back();
        }
        dq.emplace_back(dp[i + 1] + A[i + 1], i + 1);

        while (!dq.empty() && dq.front().second >= i + 2) {
            dq.pop_front();
        }

        dp[i] = dq.front().first + A[dq.front().second] * (dq.front().second - i);
    }
    cout<<dp[0];
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}