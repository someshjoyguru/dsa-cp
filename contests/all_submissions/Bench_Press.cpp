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

string solve(){
    in(n) in(w) in(wr)
    vin(v,n)
    if (wr>=w) return "YES";
    map<ll,ll> mp;
    ll ans=wr;
    f(i,0,n){
        mp[v[i]]++;
        if(mp[v[i]]==2){
            ans+=(v[i]*2);
            mp[v[i]]=0;
        }
    }
    if (ans>=w) return "YES";
    else return "NO";
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)cout<<solve()<<endl;
}