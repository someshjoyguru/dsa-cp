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

const ll MM = 1000000;
vector<bool> vec(MM+10, true);
vll pr;

void sieve() {
    vec[0] = false;
    vec[1] = false;
    for (ll i = 2; i*i <= MM; i++) {
        if (vec[i]) {
            for (ll j = i*i; j <= MM; j += i) {
                vec[j] = false;
            }
        }
    }
    for (ll i = 2; i <= MM; ++i) {
        if (vec[i]) {
            pr.push_back(i);
        }
    }
}

ll func(ll k) {
    for (ll pr : pr) {
        if (pr * pr > k) break;
        if (k % pr == 0) return pr;
    }
    return k; 
}


void solve(){
    in(k)
    ll p = func(k);
    ll sum = 0;
    for (ll pr : pr) {
        if (pr > p) break;
        sum += pr;
    }
    ll sp=sum;
    ll res = k * sp;
    cout << res << endl;
}

int main(){
    fast;
    int t=1;
    sieve();
    cin >> t;
    while(t--)solve();
}
