#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll> v(26,0);
    for(ll i=0;i<n;i++){
        v[s[i]-'A']++;
    }
    ll c=0;
    for (ll i=0; i<26; i++){
        if (v[i]>=i+1)c++;
    }
    cout<<c<<endl;
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}