#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n,m;
    cin>>n>>m;
    priority_queue<ll,vector<ll>> a;
    priority_queue<ll,vector<ll>,greater<ll>> b;
    
    for (ll i=0; i<n; i++){
        ll x;
        cin>>x;
        a.push(x);
    }
    for (ll i=0; i<m; i++){
        ll x;
        cin>>x;
        b.push(x);
    }
    ll sum=0;
    for (ll i=0; i<n; i++){
        sum+=abs(a.top()-b.top());
        a.pop();
        b.pop();
    }
    cout<<sum<<endl;
}

int main(){
    fastio()
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}