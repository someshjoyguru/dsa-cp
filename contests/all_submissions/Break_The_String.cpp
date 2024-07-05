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

void solve() {
    sin(s)
    ll n = s.size();
    vll pp(n);
    vll dp(n + 1);

    pp[0] = 1;
    f(i,1,n){
        pp[i] = pp[i - 1] * 53;
    }

    dp[0] = 0;
    f(i,0,n){
        dp[i + 1] = (dp[i] + (s[i]-'a'+ 1) * pp[i]);
    }

    auto func = [&](int l, int r) -> ll {
        return ((dp[r] - dp[l]) * pp[n - 1 - l]);
    };

    ll cnt = 0;
    f(i,0,n){
        ll rem=n-2*i;
        if (rem % 2 == 1) continue;
        if (func(0, i) == func(i, 2 * i)) {
            ll hrem = rem / 2;
            if (func(2 * i + hrem, n)==func(2 * i, 2 * i + hrem)) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}
