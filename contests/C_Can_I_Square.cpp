#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll sum=0;
    for (ll i=0; i<n; i++){
        cin>>a[i];
        sum+=a[i];
    }

    // ll sum =accumulate(a.begin(), a.end(),0);
    // ll x = sqrt(sum);
    // if (x*x==sum) {
    //     cout << "YES"<<endl;
    // }
    // else {
    //     cout << "NO"<<endl;
    // }
    if (sum >= 0) {
        ll sr = sqrt(sum);
        if(sr*sr==sum){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}