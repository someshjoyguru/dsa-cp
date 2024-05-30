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
    string s; cin>>s;
    ll length = 0, breadth = 0;
    if (s[0]=='1' && s[1]=='1') length=21;
    else if (s[0]=='1' || s[1]=='1') length=11;
    else length=1;

    if (s[2]=='1' && s[3]=='1') breadth=21;
    else if (s[2]=='1' || s[3]=='1') breadth=11;
    else breadth=1;

    cout<<length*breadth<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}