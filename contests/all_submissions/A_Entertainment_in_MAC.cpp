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
    ll n; cin>>n;
    string s; cin>>s;
    string rev=s;
    for (int i=0; i<s.size()/2; i++)swap(rev[i],rev[s.size()-1-i]);
    string k=s+rev;
    reverse(pura(k));
    cout<<min({s,rev+s,k})<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}