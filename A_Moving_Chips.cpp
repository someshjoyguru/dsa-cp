#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


void solve(){
    ll n; cin>>n;
    vector<ll> v(n);
    for (ll i=0; i<n; i++)cin>>v[i];
    ll start=-1,end=-1;
    ll c=0;
    for (ll i=0; i<n; i++){
        c+=v[i];
        if (start==-1 && v[i]==1)start=i;
        else if (v[i]==1)end=i;
    }
    if (c==1) cout<<0<<endl;
    else cout<<end-start+1-c<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}