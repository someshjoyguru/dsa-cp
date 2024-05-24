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
    in(n);
    inv(v,n);
    sort(v);
    ll sum=0;
    sum=(v[n-1]-v[0])+(v[n-2]-v[0]);
    ll sum1=(v[n-1]-v[1]+v[n-2]-v[1]);
    cout<<sum+sum1<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}