#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n),b(m);
    ll maxi = INT_MIN;
    for (int i=0; i<n; i++)cin>>a[i];
    for (int i=0; i<m; i++){
        cin>>b[i];
        maxi=max(maxi,b[i]);
    }
    sort(a.begin()+n-maxi,a.end());
    for (int i=0; i<n; i++)cout<<a[i]<<" ";
    cout<<endl;
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