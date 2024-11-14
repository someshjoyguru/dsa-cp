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

bool check(string &s, ll pos) {
    return s.substr(pos,4)=="1100";
}

void solve(){
    sin(s)
    in(q)
    set<ll> p;
    ll n=s.size();
    f(i,0,n-3){
        if (check(s, i)) {
            p.insert(i);
        }
    }
    while (q--) {
        in(i) in(v)
        i--;
        s[i] = '0' + v;
        f(j,i-3,i+1){
            if (j >= 0 && j + 3 < s.size()) {
                if (check(s, j)) {
                    p.insert(j);
                } else {
                    p.erase(j);
                }
            }
        }
        if (!p.empty()) pYES
        else pNO
    }
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}