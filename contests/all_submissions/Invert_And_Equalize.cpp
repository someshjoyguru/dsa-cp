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
    int c0=0, c1=0;
    if (s[0]=='0')c0++;
    else c1++;
    for (int i=1; i<n; i++){
        if (s[i]!=s[i-1]){
            if (s[i]=='0')c0++;
            else c1++;
        }
    }
    cout<<min(c0, c1)<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}