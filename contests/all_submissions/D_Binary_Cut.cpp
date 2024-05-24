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
    int n=s.size();
    int ind = s.find("01");
    int ind1 = s.find("10");
    if (n==1 || (ind1==-1 && ind==-1)) {
        cout<<1<<endl;
        return;
    }
    if (ind==-1){
        cout<<2<<endl;
        return;
    }
    ll c=1;
    for (int i=1; i<=ind; i++){
        if (s[i]!=s[i-1])c++;
    }
    for (int i=ind+2; i<n; i++){
        if (s[i]!=s[i-1])c++;
    }
    cout<<c<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}