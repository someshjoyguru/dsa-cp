#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(i,a,b) for (ll (i)=(a); (i)<(b); (i)++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define sin(s) string (s); cin>>(s);
#define inv(v,n) vll (v)(n); f(i,0,n)cin>>(v)[i];
#define all(v) (v).begin(),(v).end()
#define sort(v) sort(all(v));
#define pYES cout<<'YES'<<endl;
#define pNO cout<<'NO'<<endl;


void solve() {
    int n;
    cin >> n;
    ll a = -1, b = -1;
    bool prev = false;
    ll maxi = 0;

    for (int i = 0; i < n; ++i) {
        int q;
        ll x, y;
        cin >> q >> x >> y;

        if (q == 1) {
            cout << "YES" << endl;
            prev = true;
            maxi = max(x, y);
        } else {
            if (x == y) {
                cout << "YES" << endl;
                prev = false;
            } else if (prev && maxi > min(x, y)) {
                cout << "YES" << endl;
                maxi = max(x, y);
            } else {
                cout << "NO" << endl;
                prev = false;
            }
        }
    }
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}