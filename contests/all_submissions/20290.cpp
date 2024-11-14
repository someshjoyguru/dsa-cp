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
    in(l) in(r) in(k)
    ll n = r-l+1;
    if(k==1){
        cout<<n<<endl;
        return;
    }
    ll lo = l, h = r / k, y = -1;
    while (lo <= h) {
        ll m = lo + (h - lo) / 2;
        if (m * k <= r) {
            y = m;
            lo = m + 1;
        } else {
            h = m - 1;
        }
    }

    if (y >= l) {
        cout << y - l + 1 << endl;
    } else {
        cout << 0 << endl;
    }
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}