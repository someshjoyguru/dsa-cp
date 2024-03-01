#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// 0 1 2
void solve(){
    ll n; cin>>n;
    vector<ll> v(n);
    ll a=0,b=0,sum=0;
    for (ll i=0; i<n; i++){
        cin>>v[i];
        if (v[i]%3==1){
            a++;
        }else if (v[i]%3==2){
            b++;
        }
        sum+=v[i];
    }
    ll c=(sum+3)%3;
    if (c==2){
        if (b)cout<<1<<endl;
        else if (a%3==2)cout<<1<<endl;
        else cout<<2<<endl;
    }else if (c==1){
        if (a)cout<<1<<endl;
        else cout<<2<<endl;
    }else{
        cout<<0<<endl;
    }
    // if (c==2) c=1;
    // cout<<c<<endl;
    
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}