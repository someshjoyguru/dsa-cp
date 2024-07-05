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

void solve()
{  
    in(n) in(l) in(r)
    vin(a,n);
    ll ans = 0;
    long long sum = 0;
    ll start = 0;

    for (ll end = 0; end < n; ++end) {
        sum += a[end];

        while (sum > r && start <= end) {
            sum -= a[start++];
        }

        if (sum >= l && sum <= r) {
            ++ans;
            sum = 0;
            start = end + 1;
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