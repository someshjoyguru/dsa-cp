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
    ll mod=1e9+7;
    in(n) in(k)
    sin(s)
    map<char, int> mp;
    mp['a']++; mp['e']++; mp['i']++; mp['o']++; mp['u']++;
    vector<ll> v;
    f(i,0,n){
        if (mp[s[i]])v.push_back(i);
    }
    ll i=k;
    ll ans=1;
    while(i<v.size()){
        ans*=(v[i]-v[i-1]);
        i+=k;
    }
    cout<<ans<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}