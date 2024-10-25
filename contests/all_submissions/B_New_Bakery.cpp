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
    in(n) in(a) in(b)
    ll k = min(n,b);
    if (b>=a){
        ll i=b+1-a;
        if (i>n){
            cout<<(b+1)*n-(n*(n+1)/2)<<endl;
            return;
        }
        ll ch = b*i -i*(i+1)/2 +i;
        cout<<ch+(n-i)*a<<endl;
    }else{
        cout<<n*a<<endl;
    }
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}