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
    ll n,k;
    cin>>n>>k;
    inv(v,n);

    ll d=k/2;
    ll rem=k%2;
    ll l=0, r=n-1;
    for (int i=0; i<n; i++){
        if (d>=v[i]){
            d-=v[i];
            l++;
        }else{
            v[i]-=d;
            if (rem)v[i]--;
            if(v[i]==0)l++;
            break;
        }
    }
    if (l>=n){
        cout<<n<<endl;
        return;
    }
    d=k/2;
    for (int i=n-1; i>=0; i--){
        if (d>=v[i]){
            d-=v[i];
            r--;
        }else{
            v[i]-=d;
            break;
        }
        if (r<l){
            cout<<n<<endl;
            return;
        }
    }
    if (r<0){
        cout<<n<<endl;
        return;
    }

    if (r<l){
        cout<<n<<endl;
        return;
    }
    cout<<n-(r-l+1)<<endl;
    return;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}