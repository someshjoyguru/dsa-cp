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
#define pYES cout<<'YES'<<endl;
#define pNO cout<<'NO'<<endl;

void solve(){
    in(n)
    vin(v,n)
    map<ll,vll> mp;
    ll maxi=0;
    ll id=0;
    for (ll i=0; i<n; i++){
        ll c=v[i];
        if (mp.find(c)==mp.end()){
            if (mp.find(c-1)!=mp.end()){
                mp[c-1].push_back(i+1);
                mp[c]=mp[c-1];
                mp.erase(c-1);
                if (maxi>mp[c].size()){
                    maxi=c;
                }
            }else mp[c].push_back(i+1);
        }else mp[c].push_back(i+1);
    }
    vll vv=mp[maxi];
    for (ll c:vv)cout<<c<<" ";
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}