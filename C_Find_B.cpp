#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


void solve(){
    ll n,q;
    cin>>n>>q;
    vector<ll> c(n);
    for (ll i=0; i<n; i++)cin>>c[i];
    
    // preprocessing
    vector<ll> pre(n),ones(n,0);
    for (ll i=0; i<n; i++){
        if (i==0) pre[i]=c[i];
        else pre[i]=pre[i-1]+c[i];
        if (i==0) ones[i]=(c[i]==1);
        else ones[i]=ones[i-1]+(c[i]==1);
    }

    // queries
    while(q--){
        ll l,r;
        cin>>l>>r;
        if (l==r){
            cout<<"NO"<<endl;
            continue;
        }
        ll one;
        if (l==1) one=ones[r-1];
        else one=ones[r-1]-ones[l-2];

        ll sum;
        if (l==1) sum=pre[r-1];
        else sum=pre[r-1]-pre[l-2];

        ll cost=one*2+(r-l+1-one)*1;
        if (cost>sum){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
}


/*
1 2 1 4 1


*/
int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}