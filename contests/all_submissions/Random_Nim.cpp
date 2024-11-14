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
#define pNO cout<<"NO"<<endl;\
// const ll MOD = 1e9 + 7;

ll mod_exp(ll base, ll exp, int mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

pair<ll, ll> fff(int D) {
    ll P = D + (D * (D - 1)) / 2;
    ll Q = D * D;
    ll MOD = 1e9 + 7;
    return {P % MOD, Q % MOD};
}

void solve(){
    in(n) in(d)
    vin(v,n)
    int x = accumulate(all(v), 0, [](ll a, ll b) { return a ^ b; });

    auto [P, Q] = fff(d);

    if (x == 0) cout << 0 << endl;
    else {
        ll MOD = 1e9 + 7;
        ll inv = mod_exp(Q, MOD - 2, MOD);
        ll res = (P * inv) % MOD;
        cout << res << endl;
    }
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}