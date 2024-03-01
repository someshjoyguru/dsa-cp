#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(n) for (ll z=0; z<n; z++)
#define f0(n) for (ll z=n-1; z>=0; z--)
#define f1(z,n) for (ll z=0; z<n; z++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define inv(v,n) vll v(n); f(n) cin>>v[z];
#define pura(v) v.begin(),v.end()
#define sort(v) sort(pura(v));
#define prefix(v,pre) do { ll sz=v.size(); pre.resize(sz); f(sz) pre[z] = (z==0) ? v[z] : v[z] + pre[z-1]; } while(0)
#define suffix(v,suf) do { ll sz=v.size(); suf.resize(sz); f0(sz) suf[z] = (z==sz-1) ? v[z] : v[z] + suf[z+1]; } while(0)
#define coutv(v,n) f(n) cout<<v[z]<<" "; cout<<endl;

void solve(){
    in(n);
    inv(v,n);
    in(q);
    vll pre, suf;
    prefix(v, pre);
    // coutv(pre,n);
    f(q){
        in(l); in(u);
        if(l!=1)u+=pre[l-2];
        auto lb = lower_bound(pura(pre),u);
        cout<<lb-pre.begin()+1<<" ";
    }
    cout<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--) solve();
}
