#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for (ll i=0; i<n; i++)cin>>v[i];
    if (n==1){
        cout<<v[0]<<endl;
        return;
    }
    // vector<ll> ans;
    // ans.push_back(v[0]);
    // ans.push_back((v[0]+v[1]/2)*2);
    vector<ll> od(n,0);
    vector<ll> ev(n,0);
    for (ll i=0; i<n; i++){
        if (i==0){
            if (v[i]%2){
                od[0]=1;
            }else{
                ev[0]=1;
            }
        }else{
            if (v[i]%2){
                od[i]=od[i-1]+1;
                ev[i]=ev[i-1];
            }else{
                od[i]=od[i-1];
                ev[i]=ev[i-1]+1;
            }
        }
    }
    for (ll i=0; i<n; i++)cout<<od[i]<<" ";
    cout<<endl;
    for (ll i=0; i<n; i++)cout<<ev[i]<<" ";
    cout<<endl;
    
    vector<ll> pre(n,0);
    pre[0]=v[0];
    for (ll i=1; i<n; i++){
        pre[i]=pre[i-1]+v[i];
    }
    ll x=0;
    for (ll i=0; i<n; i++){
        // cout<<pre[i]-(od[i]%2 + (i>0)?(i+1)%2:0)<<" ";
        if (i==0){
            cout<<pre[0]<<" ";
            continue;
        }
        // cout<<pre[i]-((ev[i])?(od[i]%2):ceil(od[i]/2))<<" ";
        cout<<pre[i]-((od[i]%3==1)?1:0)-od[i]/3<<" ";
    }
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