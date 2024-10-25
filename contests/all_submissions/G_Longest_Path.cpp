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
    in(n) in(m)
    vll adj[n+1];
    f(i,0,m){
        in(u) in(v)
        adj[u].push_back(v);
    }
    ll maxi=0;
    vll visi(n+1,0);

    function<void(ll, ll)> fa = [&](ll u, ll l)->void{
        visi[u]=1;
        maxi=max(maxi, l);
        for (ll v: adj[u]){
            if (visi[v]==0) fa(v,l+1);
        }
        visi[u]=0;
    };

    f(i,1,n+1) fa(i,0);
    cout<<maxi;
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}