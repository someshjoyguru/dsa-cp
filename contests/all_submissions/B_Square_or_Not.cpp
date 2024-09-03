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
    in(n)
    sin(s)
    if (n<4 || ((int)sqrt(n))*((int)sqrt(n))!=n){
        pNO
        return;
    }
    int x = ((int)sqrt(n));
    // cout<<x<<endl;
    string st(x,'1');
    string stt = '1'+ string(x-2,'0') +'1';
    // cout<<st<<" "<<stt<<endl;
    if (s.substr(0,x)!=st || s.substr(n-x,x)!=st){
        pNO
        return;
    }
    for (int i=x; i<n-x; i+=x){
        string c = s.substr(i,x);
        if (c!=stt){
            pNO
            return;
        }
    }
    pYES
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}