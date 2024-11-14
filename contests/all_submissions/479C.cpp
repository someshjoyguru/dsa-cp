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
    vector<vll> v;
    f(i,0,n){
        in(a) in(b)
        v.push_back({a,b});
    }
    sort(v)
    ll last=min(v[0][0],v[0][1]);
    f(i,1,n){
        if (v[i][1]>=last){
            last=v[i][1];
        }else{
            last=v[i][0];
        }
    }
    cout<<last;
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}