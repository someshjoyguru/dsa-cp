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
    ll maxi=v[0];
    ll x=0;
    ll c=1;
    for (int i=0; i<n-1; i++){
        if (v[i]>v[i+1]){
            c=0;
            break;
        }
    }
    if (c){
        cout<<"Yes"<<endl;
        return;
    }

    for (int i=0; i<n-1; i++){
        if (v[i]>v[i+1]){
            x=max(x,v[i]-v[i+1]);
        }
    }
    vector<ll> ind;
    for (int i=0; i<n-1; i++){
        if (v[i]>v[i+1]){
            // v[i+1]+=x;
            ind.push_back(i+1);
        }
    }

    for (int i=0; i<ind.size(); i++){
        v[ind[i]]+=x;
    }
    for (int i=0; i<n-1; i++){
        if (v[i]>v[i+1]){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
    return;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}