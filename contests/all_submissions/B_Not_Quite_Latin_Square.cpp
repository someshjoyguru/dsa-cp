#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    char a[3][3];
    ll x,y;
    for (ll i=0; i<3; i++){
        string s; cin>>s;
        for (ll j=0; j<3; j++){
            if (s[j]=='?'){
                x=i;y=j;
            }
            a[i][j]=s[j];
        }
    }
    vector<ll> v(3,0);
    for (ll i=0; i<3; i++){
        v[a[x][i]-'A']++;
    }
    for (ll i=0; i<3; i++){
        if (v[i]==0)cout<<char(i+65)<<endl;
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