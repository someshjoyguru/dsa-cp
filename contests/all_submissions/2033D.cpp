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
    map<ll,ll> mp;
    ll c=0;
    ll ans=0;
    ll last=-2;
    mp[0]=-1;
    f(i,0,n){
        c+=v[i];
        if (mp.count(c)>0 && last<=mp[c]){
            ans++;
            last=i;
            // cout<<i<<" ";
        }
        mp[c]=i;
    }
    // cout<<endl;
    cout<<ans<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}