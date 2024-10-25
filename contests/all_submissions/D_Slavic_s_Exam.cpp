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
    sin(s) sin(t)
    ll i = 0, j = 0;
    ll n = s.length();
    ll m = t.length();
    string res;
    while (i < n && j < m) {
        if (s[i] == t[j] || s[i] == '?') {
            res += t[j];
            i++;
            j++;
        } else {
            res += s[i];
            i++;
        }
    }

    while (i<n) {
        if (s[i] == '?'){
            res += 'a';
        }else res += s[i];
        i++;
    }

    if (j == m) {
        pYES
        cout << res << endl;
    } else {
        pNO
    }
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}