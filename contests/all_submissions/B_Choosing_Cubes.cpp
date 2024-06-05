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
#define pYES cout<<"YES"<<endl;
#define pNO cout<<"NO"<<endl;

void solve(){
    in(n) in(f) in(k)
    vin(v,n)
    if (n==k) {
        pYES
        return;
    }
    ll val = v[f-1];
    sort(v.rbegin(), v.rend());
    auto ub = upper_bound(all(v), val,greater<ll>()); 
    auto lb = lower_bound(all(v), val, greater<ll>());
    ll start = lb-v.begin();
    ll end = ub-v.begin();
    // cout<<start<<" "<<end<<endl;
    if (k>=end){
        pYES
    }else if (k<=start){
        pNO
    }else{
        cout<<"MAYBE"<<endl;
    }
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}