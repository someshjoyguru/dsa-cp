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
        in(x) in(y)
        v.push_back({x,y});
    }
    sort(v)
    reverse(all(v));
    set<ll> st;
    ll ans=0;
    f(i,0,n){
        ll x=v[i][0];
        ll y=v[i][1];
        ll ub=distanupper_bound(all(st),x)-st.begin();
        ll lb=lower_bound(all(st),y)-st.begin();
        lb--;
        if (ub<=lb){
            ans+=(lb-ub+1);
            st.insert()
        }
    }
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}