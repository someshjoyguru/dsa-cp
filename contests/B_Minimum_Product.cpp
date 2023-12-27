#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll a,b,x,y,n;
    cin>>a>>b>>x>>y>>n;
    ll mini=LONG_LONG_MAX;
    ll temp=0,temp1=0;
    // n=min(n,abs(a-x)+abs(b-y));
    // for (ll i=0; i<n; i++){
    //     if ((a-i)<x || (b-(n-i))<y)continue;
    //     temp=(a-i)*(b-(n-i));
    //     mini=min(mini,temp);
    // }
    // decrease a then b
    if (a-n>=x){
        mini=b*(a-n);
    }else{
        if (b-(n-(a-x))<0){
            mini=x*y;
            cout<<mini<<endl;
            return;
        }
        mini=min(mini,x*(b-(n-(a-x))));
    }
    // decrease b then a
    if (b-n>=y){
        mini=min(mini,a*(b-n));
    }else{
        if (a-(n-(b-y))<0){
            mini=x*y;
            cout<<mini<<endl;
            return;
        }
        mini=min(mini,y*(a-(n-(b-y))));
    }
    cout<<mini<<endl;
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}