#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n; cin>>n;
    vector<ll> a(n),b(n);
    vector<ll> p(2*n),q(2*n),r(2*n),s(2*n);
    // p -> a..b c..d
    // q -> a..b d..c
    // r -> b..a c..d
    // s -> b..a d..c
    
    for (ll i=0; i<n; i++)cin>>a[i];
    for (ll i=0; i<n; i++)cin>>b[i];

    ll cnt1[2*n+1]={0};
    ll cnt2[2*n+1]={0};

    ll temp=1;
    cnt1[a[0]]++;
    for (ll i=1; i<n; i++){
        if (a[i]==a[i-1])temp++;
        else temp=1;
        cnt1[a[i]]=max(temp,cnt1[a[i]]);
    }

    temp=1;
    cnt2[b[0]]++;
    for (ll i=1; i<n; i++){
        if (b[i]==b[i-1])temp++;
        else temp=1;
        cnt2[b[i]]=max(temp,cnt2[b[i]]);
    }
    ll maxi=1;
    for (ll i=0; i<2*n+1; i++){
        maxi=max(maxi,cnt1[i]+cnt2[i]);
    }
    cout<<maxi<<endl;
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