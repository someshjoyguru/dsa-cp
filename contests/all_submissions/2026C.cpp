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

void solve(){
    in(n)
    sin(s)
    ll mini=0;
    ll i=0, j=n; 
 
    ll save = 0;
    ll debt = 0;
 
    for (int i = n - 1; i >= 0; i--)
        if (s[i] == '1' && i > debt) {
            save += i + 1;
            debt++;
        } else {
            debt = max(debt - 1, 0LL);
        }
 
    cout << n * (n + 1LL) / 2 - save << '\n';
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}