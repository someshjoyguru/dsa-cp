#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long


void solve(){
    ll n; cin>>n;
    vector<ll> a(n);
    for (ll i=0; i<n; i++)cin>>a[i];
    char c ='a';
    string s="";
    vector<ll> v(26,0);
    map<char,ll> mp;
    for (ll i=0; i<n; i++){
        for (ll j=0; j<26; j++){
            if (v[j]==a[i]){
                s+=('a'+j);
                v[j]++;
                break;
            }
        }
    }
    cout<<s<<endl;

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