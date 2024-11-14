#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(i,a,b) for (ll (i)=(a); (i)<(b); (i)++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define sin(s) string (s); cin>>(s);
#define vin(v,n) vll (v)(n); f(i,0,n)cin>>(v)[i];
#define all(v) (v).begin(),(v).end()
#define sort(v) sort(all(v));
#define pYES cout<<'YES'<<endl;
#define pNO cout<<'NO'<<endl;

void solve(){
    in(n)
    if (n==1){
        cout<<0;
        return;
    }
    ll p = 1;
    ll x = 0;
    while (p <= n) {
        if (p == n) {
            cout << x << endl;
            return;
        }
        if (p > ULLONG_MAX / 3) break;
        p *= 3;
        x++;
    }

    cout << -1;
    return;
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}
