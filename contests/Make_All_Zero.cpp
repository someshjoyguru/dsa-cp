#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n;
    cin>>n;
    ll a[n];
    ll b[n];
    ll maxi=INT_MIN;
    ll mini = INT_MAX;
    for (ll i=0; i<n; i++){
        cin>>a[i];
        maxi=max(maxi,a[i]);
        b[i]=min(mini,a[i]);
        mini=b[i];
    }
    ll count=0;
    for (ll i=0; i<n; i++){
        if (b[i]<i+1){
            count=b[i];
            break;
        }
    }
    for (ll i=0; i<n; i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    ll x=0;
    for (ll i=0; i<n; i++){
        if (a[i]>count){
            x++; 
        }
    }
    cout<<min(n,x+count)<<endl;
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