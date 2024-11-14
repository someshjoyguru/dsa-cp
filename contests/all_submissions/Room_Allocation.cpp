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
// #define sort(v) sort(all(v));
#define pYES cout<<'YES'<<endl;
#define pNO cout<<'NO'<<endl;

// static bool comp(const vll &x, const vll &y){
//     if (x[1]!=y[1]) return (x[1]<y[1]);
//     return x[0]>y[0];
// }

static bool comp1(const vll &x, const vll &y){
    if (x[0]!=y[0]) return x[0]<y[0];
    return x[1]>y[1];
}

void solve(){
    in(n)
    vector<vll> v;
    f(i,0,n){
        in(x) in(y)
        v.push_back({x,y});
    }
    // sort(all(v), comp);
    vector<vll> tt;
    f(i,0,n){
        tt.push_back({v[i][0],1});
        tt.push_back({v[i][1],-1});
    }
    sort(all(tt), comp1);
    ll c=0, maxi=0;
    f(i,0,2*n){
        c+=tt[i][1];
        maxi=max(maxi,c);
        if (i%2==0)cout<<c<<" ";
    }
    cout<<maxi;
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}