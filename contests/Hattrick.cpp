#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    vector<char> v(6);
    for (int i=0 ;i<6; i++){
        cin>>v[i];
    }
    ll temp=0,maxi=0;
    for (int i=0; i<6; i++){
        if (v[i]=='W')temp++;
        else temp=0;
        maxi=max(maxi,temp);
    }
    if (maxi>=3) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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