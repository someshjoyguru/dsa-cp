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
    vin(a,n)
    vin(b,n)
    in(m)
    vin(d,m)
    multiset<ll> st1, st2, st3;
    f(i,0,n){
        st1.insert(b[i]);
        if (a[i]!=b[i]){
            st2.insert(b[i]);
            st3.insert(b[i]);
        }
    }
    ll cnt=0;
    f(i,0,m){
        ll val = d[i];
        if (st1.find(val)!=st1.end()){
            cnt=0;
            if (st3.find(val)!=st3.end()) {
                auto it = st3.find(val);
                st3.erase(it);
            }
        }else{
            cnt++;
        }
    }
    if (cnt or st3.size()!=0) pNO
    else pYES
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}