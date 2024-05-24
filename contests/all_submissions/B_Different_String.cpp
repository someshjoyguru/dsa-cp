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
    string s;
    cin>>s;
    int f=0;
    for (int i=1; i<s.size(); i++){
        if (s[i]!=s[0]){
            f=1;
            break;
        }
    }
    if (f){
        cout<<"YES"<<endl;
        string t=s;
        while (t==s){
            next_permutation(s.begin(),s.end());
        }
        cout<<s<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}