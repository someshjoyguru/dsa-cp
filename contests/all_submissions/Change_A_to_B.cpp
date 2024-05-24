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
    ll a, b, k;
    cin>>a>>b>>k;
    ll c=0;
    while (a!=b){
        if (b%k!=0 ){
            ll op = (b-((b/k)*k));
            c+=op;
            b-=op;
        }else if (b/k>=a){
            c++;
            b=b/k;
        }else{
            c+=(b-a);
            break;
        }
    }
    cout<<c<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}

