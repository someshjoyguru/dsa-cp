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

// void solve1(){
//     in(x) in(y) in(z) in(k)
//     ll cnt=0;
//     f(i,1,x+1){
//         ll dim =k;
//         ll temp=0;
//         if (dim%i==0){
//             dim/=i;
//             temp+=(x-i+1);
//             f(j,1,y+1){
//                 if (dim%j==0){
//                     ll left = dim/j;
//                     ll way=temp*(y-j+1);
//                     if (left<=z && left>=1){
//                         cnt+=way;
//                     }
//                 }
//             }
//         }
//     }
//     cout<<cnt<<endl;
// }

vector<tuple<ll, ll, ll>> ff(ll k) {
    vector<tuple<ll, ll, ll>> fac;
    for (ll a = 1; a * a * a <= k; ++a) {
        if (k % a == 0) {
            ll a1 = k / a;
            for (ll b = a; b * b <= a1; ++b) {
                if (a1 % b == 0) {
                    ll c = a1 / b;
                    fac.emplace_back(a, b, c);
                    if (a != b) fac.emplace_back(b, a, c);
                    if (a != c) fac.emplace_back(c, a, b);
                    if (b != c) fac.emplace_back(a, c, b);
                    if (b != c && a != b) fac.emplace_back(b, c, a);
                    if (c != a) fac.emplace_back(c, b, a);
                }
            }
        }
    }
    return fac;
}


void solve(){
    in(x) in(y) in(z) in(k)
    auto fac = ff(k);
        ll maxiP = 0;

        for (auto& [a, b, c] : fac) {
            if (a <= x && b <= y && c <= z) {
                ll p = (x - a + 1) * (y - b + 1) * (z - c + 1);
                maxiP = max(maxiP, p);
            }
            if (a <= x && c <= y && b <= z) {
                ll p = (x - a + 1) * (y - c + 1) * (z - b + 1);
                maxiP = max(maxiP, p);
            }
            if (b <= x && a <= y && c <= z) {
                ll p = (x - b + 1) * (y - a + 1) * (z - c + 1);
                maxiP = max(maxiP, p);
            }
            if (b <= x && c <= y && a <= z) {
                ll p = (x - b + 1) * (y - c + 1) * (z - a + 1);
                maxiP = max(maxiP, p);
            }
            if (c <= x && a <= y && b <= z) {
                ll p = (x - c + 1) * (y - a + 1) * (z - b + 1);
                maxiP = max(maxiP, p);
            }
            if (c <= x && b <= y && a <= z) {
                ll p = (x - c + 1) * (y - b + 1) * (z - a + 1);
                maxiP = max(maxiP, p);
            }
        }

        cout << maxiP << endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}