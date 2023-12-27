#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for (int i=0; i<n; i++)cin>>v[i];
    ll neg=0;
    bool zero = false;
    ll index=0;
    for (int i=0 ; i<n; i++){
        if (v[i]<0){
            neg++;
            index=i;
        }
        if (v[i]==0)zero=true;
    }
    if (zero){
        cout<<0<<endl;
        return;
    }
    if (neg%2){
        cout<<0<<endl;
    }else{
        cout<<1<<endl;
        cout<<index+1<<" "<<0<<endl;
    }
    return;
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}