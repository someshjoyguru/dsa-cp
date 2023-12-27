#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    ll x,y;
    vector<ll> v(4,-1);
    // vector<vector<ll>> v(n,vector<ll> (2,0));
    for (int i=0; i<n; i++){
        cin>>x>>y;
        if (x<0) v[2]=0;
        if (x>0) v[3]=0;

        if (y<0) v[1]=0;
        if (y>0) v[0]=0;
    }
    if (accumulate(v.begin(),v.end(),0)!=0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}