#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for (int i=0; i<n; i++)cin>>v[i];
    if (n==1){
        cout<<1<<endl;
        return;
    }
    sort(v.begin(),v.end());
    ll maxi=v[n-1];
    ll gcd=v[1]-v[0];
    for (int i=2; i<n; i++){
        gcd=__gcd(gcd,v[i]-v[i-1]);
    }
    if (gcd==0){
        cout<<1<<endl;
        return;
    }
    ll cnt=0;
    for (int i=0; i<n; i++)
        cnt+=(maxi-v[i])/gcd;
    // for (int i=0; i<n; i++)cout<<v[i]<<" ";
    // cout<<endl;
    // cout<<gcd<<endl;
    ll x=LONG_MAX;
    for (int i=n-1; i>0; i--){
        if (v[i]-gcd>v[i-1])
            x=min(x,(maxi-(v[i]-gcd)));
    }
    x=min(x,maxi-(v[0]-gcd));
    cnt+=(x/gcd);
    cout<<cnt<<endl;
    return;
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}