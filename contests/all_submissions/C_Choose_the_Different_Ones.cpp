#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n),b(m), fa(k,0),fb(k,0);
    for (ll i=0; i<n; i++)cin>>a[i];
    for (ll i=0; i<m; i++)cin>>b[i];
    for (ll i=0; i<n; i++){
        if (a[i]<=k)fa[a[i]-1]++;
    }
    for (ll i=0; i<m; i++){
        if (b[i]<=k)fb[b[i]-1]++;
    }
    ll x=0,y=0;
    for (ll i=0; i<k; i++){
        if (fa[i]==0 && fb[i]==0){
            cout<<"NO"<<endl;
            return;
        }else{
            if (fa[i]!=0)x++;
            if (fb[i]!=0)y++;
        }
    }
    if (x<k/2 or y<k/2){
        cout<<"NO"<<endl;
        return;
    }else {
        cout<<"YES"<<endl;
        return;
    }

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