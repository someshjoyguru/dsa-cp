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


ll func(vector<ll> a, ll l, ll r){
    ll n=r-l+1;
    ll c=a[l];

    bool fp=1;
    for (ll i=l; i<=r; i+=2){
        if(a[i]!=c){
            return min(n-i-1,i-2);
        }
    }
    if (fp){
        c=a[l];
        ll ans=INT_MAX;
        if (a[l]==a[l+1] or a[r]==a[r-1]){
            for (ll i=l+1; i<=r; i++){
                if(a[i]!=c){
                    ans=min(n-i-1,i-2);
                }
            }
            c=a[r];
            for (ll i=r; i>=l; i--){
                if(a[i]!=c){
                    ans=min({ans,n-i-1,i-2});
                }
            }
            return ans;
        }
        return 1;
    }
}

void solve(){
    in(n);
    inv(a,n);
    ll c=a[0];
    bool flag=1;
    for (ll i=0; i<n; i++){
        if(a[i]!=c){
            flag=0;
            break;
        }
    }
    if (flag){
        cout<<"-1\n";
        return;
    }
  
    // ll ans=INT_MAX;
    
    if (n%2){
        cout<<func(a,0,n-1)<<endl;
    }else{
        cout<<min(func(a,0,n-2),func(a,1,n-1))<<endl;
    }
    
    return;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}