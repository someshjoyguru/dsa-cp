#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n; cin>>n;
    ll i,j;
    vector<ll> vec(n+1);
    for(i=1;i<=n;i++)cin>>vec[i];

    vector<ll>v(n+1,0);
    if(vec[1]!=n){
        cout<<"NO"<<endl;
        return;
    }

    for(i=1;i<=n;i++)v[vec[i]]++;
    for(i=n-1;i>=1;i--)v[i]=v[i+1]+v[i];

    for(i=1;i<=n;i++){
        if(vec[i]!=v[i]){
            cout<<"NO"<<endl;
            return;
        }
    }
    
    cout<<"YES"<<endl;
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