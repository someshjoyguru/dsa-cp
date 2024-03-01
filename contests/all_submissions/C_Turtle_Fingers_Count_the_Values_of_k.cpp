#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int func(int a, int l){
    ll ad=1,x=0;
    while(l%ad==0){
        x++;
        ad=ad*a;
    }
    return x;
}

void solve(){
    ll a,b,l;
    cin>>a>>b>>l;
    if (__gcd(a,l)==1 && __gcd(b,l)==1){
        cout<<1<<endl;
        return;
    }
    ll ans=0;
    ll x=func(a,l),y=func(b,l);
    map<ll,ll> mp;
    for (ll i=0; i<x; i++){
        for (ll j=0; j<y; j++){
            ll k = (pow(a,i)*pow(b,j));
            if (l%k==0 && mp.find(l/k)==mp.end()){
                ans++;
                mp[l/k]++;
            }

        }
    }
    cout<<ans<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}