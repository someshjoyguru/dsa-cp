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
    set<char> st;
    for (char c: s){
        st.insert(c);
    }
    string en;
    map<char, char> mp;
    for (char c: st){
        en+=c;
    }
    for (int i=0; i<en.length(); i++){
        mp[en[i]]=en[en.length()-1-i];
    }
    string ans=s;
    for (int i=0; i<n; i++){
        ans[i]=mp[ans[i]];
    }
    cout<<ans<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}