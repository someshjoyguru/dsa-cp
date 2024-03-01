#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


void solve(){
    ll n; cin>>n;
    vector<ll> v(n);
    ll sum=0;
    for (ll i=0; i<n; i++)cin>>v[i],sum+=abs(v[i]);
    cout<<sum<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}