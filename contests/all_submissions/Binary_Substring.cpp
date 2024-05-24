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
    string s; cin>>s;
    int i=n-1,j=i;
    int c=0;
    while(j>0 && i>0){
        i=n-1;
        while(i>=0 && s[i]=='1')i--;
        if (i<0)break;
        int j=i;
        while(j>=0 && s[j]=='0')j--;
        if (i<0 or j<0)break;
        if ((i-j)>1){
            c++;
            swap(s[i],s[j]);
            if (i>0 && j>0)swap(s[i-1],s[j-1]);
            else break;
        }
        if (i<0 or j<0)break;
    }
    cout<<c<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}