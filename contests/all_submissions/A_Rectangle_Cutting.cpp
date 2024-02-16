#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll a,b;
    cin>>a>>b;
    if (a<b)swap(a,b);
    if (a%2 && b%2){
        cout<<"No"<<endl;
        return;
    }
    if (a%2 && b%2==0){
        if (b/2==a)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
        return;
    }
    if (b%2 && a%2==0){
        if (a/2==b)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
        return;
    }
    if (a%2==0 && b%2==0){
        if (b/2==a && a/2==b)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
        return;
    }
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