#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long


void solve(){
    ll n; cin>>n;
    vector<pair<ll,ll>> com(n);
    vector<ll> a(n+1),b(n+1);
    // vector<ll> posa(n+1),posb(n+1);
    for (ll i=0; i<n; i++){
        // cin>>a[i];
        // posa[a[i]]=i+1;
        cin>>com[i].first;
    }
    for (ll i=0; i<n; i++){
        // cin>>b[i];
        cin>>com[i].second;
        // posb[b[i]]=i+1;
    }
    sort(com.begin(),com.end());
    for (ll i=0; i<n; i++){
        // com[i]={posa[i+1],posb[i+1]};
        // com[i]={a[i],b[i]};
        cout<<com[i].first<<" ";
    }
    cout<<endl;
    for (ll i=0; i<n; i++){
        // com[i]={posa[i+1],posb[i+1]};
        // com[i]={a[i],b[i]};
        cout<<com[i].second<<" ";
    }
    cout<<endl;
    // for (ll i=0; i<n; i++)cout<<com[i].first<<" ";
    // cout<<endl;
    // for (ll i=0; i<n; i++)cout<<com[i].second<<" ";
    // cout<<endl;

    // for (ll i=1; i<=n; i++)cout<<a[i]<<" ";
    // cout<<endl;
    // for (ll i=1; i<=n; i++)cout<<com[i]<<" ";
    // cout<<endl;
    
       
}

int main(){
    fastio();
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}