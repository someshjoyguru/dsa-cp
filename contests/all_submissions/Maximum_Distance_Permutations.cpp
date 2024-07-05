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
    ll m = n/2 +n%2;
    f(i,1,n+1)cout<<i<<" ";
    cout<<endl;
    for (int i=m+1; i<=n; i++)cout<<(i)<<" ";
    for (int i=1; i<=m; i++)cout<<(i)<<" ";
    cout<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}