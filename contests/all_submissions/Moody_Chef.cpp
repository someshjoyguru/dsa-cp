#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(n)for (ll z=0; z<n; z++)
#define f1(z,n)for (ll z=0; z<n; z++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define inv(v,n) vll v(n); f(n)cin>>v[z];
#define pura(v) v.begin(),v.end()
#define sort(v) sort(pura(v));

void solve(){
    ll n,l,r;
    cin>>n>>l>>r;
    ll c=0;
    inv(v,n);
    ll mini=0, maxi=0;
    for (ll i=0; i<n; i++){
        if (v[i]<=r and v[i]>=l)c++;
        else c--;
        mini=min(mini,c);
        maxi=max(maxi,c);
    }
    cout<<maxi<<" "<<mini<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}