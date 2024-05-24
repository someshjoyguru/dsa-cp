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
    ll a, b, c,d;
    cin>>a>>b>>c>>d;
    ll p=min(a,b), q=max(a,b);
    ll r=min(c,d), s=max(c,d);
    if ((p<r && q>s)||(p>r && q<s)||(p<r && p<s && q<r && q<s)||(p>r && p>s && q>r && q>s))cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}