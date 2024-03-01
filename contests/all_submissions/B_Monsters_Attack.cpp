#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n),x(n);
    for (ll i=0; i<n; i++)cin>>a[i];
    for (ll i=0; i<n; i++)cin>>x[i],x[i]=abs(x[i]);
    vector<pair<ll,ll>> v(n);
    for (ll i=0; i<n; i++){
        v[i]={x[i],a[i]};
    }
    sort(v.begin(),v.end());
    ll c=0;
    ll time=0;
    for (ll i=0; i<n; i++){
        ll cost=v[i].second;
        c+=k*(v[i].first-time);
        time=v[i].first;
        if (c<cost){
            cout<<"NO"<<endl;
            return;
        }else{
            c-=cost;
        }
    }
    cout<<"YES"<<endl;
    return;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}