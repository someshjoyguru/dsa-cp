#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void func(ll n, ll a, ll b, ll c, vector<pair<ll,ll>>& v){
    if (n==0)return;
    func(n-1, a, c, b,v);
    v.push_back({a,c});
    func(n-1,b,a,c,v);
}
void solve(){
    ll n;cin>>n;
    vector<pair<ll,ll>> v;
    func(n,1,2,3,v);
    cout<<v.size()<<endl;
    for (auto i : v){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return;
}

int main(){
    fastio()
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}