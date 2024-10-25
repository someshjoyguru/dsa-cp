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
    vin(v,n)
    ll maxi=INT_MIN, maxi2=INT_MIN;
    f(i,0,n){
        if (v[i]>maxi){
            maxi2=maxi;
            maxi=v[i];
        }else if (v[i]>maxi2 && v[i]!=maxi){
            maxi2=v[i];
        }
    }
    cout<<maxi2<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}