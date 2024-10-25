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

const int mod = 1e9 + 7;

ll mod_pow(ll base, ll exp, ll mod) {
    ll ans = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            ans = (ans * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return ans;
}

ll mod_inverse(ll a, ll mod) {
    return mod_pow(a, mod - 2, mod);
}

void solve(){
    in(n)
    vll a(n);
    
    ll s = 0, ss = 0;
    f(i,0,n) {
        cin >> a[i];
        s = (s + a[i]) % mod;
        ss = (ss + a[i] * a[i]) % mod;
    }
    
    ll p = (s * s - ss + mod) % mod;
    ll q = (n * (n - 1)) % mod;
    
    ll qq = mod_inverse(q, mod);
    cout << (p * qq) % mod << endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}