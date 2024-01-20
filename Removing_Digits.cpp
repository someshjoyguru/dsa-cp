#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n; cin>>n;
    ll temp=n;
    ll cnt=0;
    while(true){
        temp=n;
        if (temp==0)break;
        ll maxi=INT_MIN;
        while(temp){
            maxi=max(maxi,temp%10);
            temp/=10;
        }
        n-=maxi;
        cnt++;
    }
    cout<<cnt;
}
// 1000000 * 7

int main(){
    fastio()
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}