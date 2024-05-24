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
    
    string x,y;
    cin>>x>>y;
    
    ll n=x.size();
    int q=1;
    for (int i=0; i<n; i++){
        if (x[i]==y[i])continue;
        if (q){
            if (x[i]<y[i]){
                swap(x[i],y[i]);
            }
                q=0;
        }else{
            if (x[i]>y[i]){
                swap(x[i],y[i]);
            }
        }
        
    }

    cout<<x<<endl;
    cout<<y<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}