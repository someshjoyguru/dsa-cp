#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n; cin>>n;
    vector<ll> a(n);
    for (int i=0; i<n; i++)cin>>a[i];
    
    vector<ll> forward(n,1),backward(n,0);
    
    forward[0]=0;
    forward[1]=1;
    backward[n-1]=0;
    backward[n-2]=1;

    for (ll i=1; i<n-1; i++){
        if (a[i]-a[i-1]>a[i+1]-a[i])forward[i+1]=forward[i]+1;
        else forward[i+1]=forward[i]+abs(a[i+1]-a[i]);
    }

    for (ll i=n-2; i>0; i--){
        if (a[i+1]-a[i]>a[i]-a[i-1])backward[i-1]=backward[i]+1;
        else backward[i-1]=backward[i]+abs(a[i]-a[i-1]);
    }

    // for (int i=0; i<n; i++)cout<<forward[i]<<" ";
    // cout<<endl;
    // for (int i=0; i<n; i++)cout<<backward[i]<<" ";
    // cout<<endl;
    ll m; cin>>m;
    while(m--){
        ll x,y;
        cin>>x>>y;
        x--;y--;
        if (x<y)cout<<forward[y]-forward[x]<<endl;
        else cout<<backward[y]-backward[x]<<endl;
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