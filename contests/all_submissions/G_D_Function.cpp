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

// bf
// ll D(ll n){
//     int sum = 0;
//     while (n != 0) {
//         sum += n % 10;
//         n /= 10;      
//     }
//     return sum;
// }
// void solve(){
//     in(l) in(r) in(k)
//     ll lo=pow(10,l);
//     ll hi=pow(10,r);
//     ll cnt=0;
//     f(i,lo,hi){
//         if (D(k*i)==k*D(i))cnt++;
//     }
//     cout<<cnt<<endl;
// }

// ll D(ll n, ll k){
//     int sum = 0;
//     while (n != 0) {
//         if ((n%10)%k!=0) return 0;
//         sum += n % 10;
//         n /= 10;      
//     }
//     return 1;
// }

const ll MOD = 1e9 + 7;

ll modExp(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void solve() {
    in(l) in(r) in(k)
    if (k > 9) {
        cout << 0 << endl;
        return;
    }
    ll cas = 9 / k + 1;
    ll casMod = cas % MOD;
    
    ll powCasR = modExp(casMod, r, MOD);
    ll powCasL = modExp(casMod, l, MOD);
    
    ll cnt = (powCasR - powCasL + MOD) % MOD;
    cout << cnt << endl;
}

// void solve2(){
//     in(l) in(r) in(k)
//     if (k>9) {
//         cout<<0<<endl;
//         return;
//     }
//     ll cas = 9/k+1;
//     ll cnt=(pow(cas,r)-1)-(pow(cas,l)-1);
//     cout<<cnt<<endl;
// }

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}