#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n,x;
    cin>>n>>x;
    string s;
    cin>>s;
    ll temp=0;
    for (int i=0; i<n; i++){
        if (s[i]=='0')temp--;
        else {
            temp=x;
        }
        if (temp<0){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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