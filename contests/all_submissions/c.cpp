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

ll func(vll& a, ll n)
{

  vll pre(n + 2);
  vll suf(n + 2);
  suf[n] = a[n - 1];

  pre[1] = a[0];
  for (ll i = 2; i <= n; i += 1)
    pre[i] = __gcd(pre[i - 1], a[i - 1]);


  for (ll i = n - 1; i >= 1; i -= 1)
    suf[i] = __gcd(suf[i + 1], a[i - 1]);

  ll ans = max(suf[2], pre[n - 1]);

  for (ll i = 2; i < n; i += 1)
    ans = max(ans, __gcd(pre[i - 1], suf[i + 1]));

  return ans;
}

void solve(){
    in(n)
    vin(v,n)
    cout<<func(v,n)<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}