#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n,k; cin>>n>>k;
    vector<ll> v(n,0);
    ll i=1,j=n;
    for (ll x=0; x<k; x+=2){
        for (ll y=x; y<n; y+=k){
            v[y]=i;
            i++;
        }
        for (ll y=x+1; y<n; y+=k){
            v[y]=j;
            j--;
        }
    }
    
    for (auto q :v)cout<<q<<" ";
    cout<<endl;
}

// 1 0 4 0 2 0 0 0 3
int main(){
    fastio()
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}