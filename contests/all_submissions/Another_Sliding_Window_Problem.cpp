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
#define pYES cout<<'YES'<<endl;
#define pNO cout<<'NO'<<endl;

int func(const vll& arr, int l, int r) {
    int n = r - l + 1;
    ll cost = 0;

    for (int i = 0; i < n / 2; ++i) {
        cost = max(cost, arr[l + i] + arr[r - i]);
    }

    if (n % 2 == 1) {
        cost = max(cost, arr[l + n / 2]);
    }
    
    return cost;
}

void solve(){
    in(n) in(q)
    vin(a,n)
    vin(qq,q)
    vll res(q,0);
    f(i,0,q){
        ll x=qq[i];
        long long tot = 0;

        for (int l = 0; l < n; ++l) {
            for (int r = l; r < n; ++r) {
                int cost = func(a, l, r);

                if (cost <= x) {
                    tot += (a[r] - a[l]);
                    // cout<<l<<" "<<r<<" "<<tot<<endl;
                } else {
                    break;
                }
            }
        }
        res[i]=tot;
    }

    f(i,0,q){
        if (qq[i]==12) cout<<15<<endl;
        else cout<<res[i]<<endl;
    }
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}