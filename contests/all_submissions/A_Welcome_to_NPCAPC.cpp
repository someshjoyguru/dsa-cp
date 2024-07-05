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

const ll mod = 998244353;

int nCr(int n, int r) {
    int sum = 1;
    for(int i = 1; i <= r; i++){
        sum = (sum * (n - r + i)/i)%mod;
    }
    // for(int i = 1; i <= r; i++){
    //     sum = (sum / i)%mod;
    // }
    return (int) sum;
}
void solve(){
    in(n)
    cout<<nCr(n, 6)<<endl;   
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}