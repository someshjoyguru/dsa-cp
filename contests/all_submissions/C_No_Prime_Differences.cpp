#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n,m;
    cin>>n>>m;
    if (n==4){
        for (int i=1; i<=4; i++){
            ll cnt=1;
            for (int j=i;; j+=4){
                if (cnt>m)break;
                cout<<j<<" ";
                cnt++;
            }
            cout<<endl;
        }
        return;
    }
    if (n==4 && m%2==1){
        bool x=0;
        for (int i=1; i<=m*n; i+=m){
            for (int j=i+x; j<=i+m-1; j++){
                cout<<j<<" ";
            }
            if(x)cout<<i+m;
            cout<<endl;
            x=(!x);
        }    
        return;
    }
    for (int i=1; i<=m*n; i+=2*m){
        for (int j=i; j<=i+m-1; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    for (int i=m+1; i<=m*n; i+=2*m){
        for (int j=i; j<=i+m-1; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    // else{
    //     bool x=0;
    //     for (int i=1; i<=m*n; i+=m){
    //         for (int j=i+x; j<=i+m-1; j++){
    //             cout<<j<<" ";
    //         }
    //         if(x)cout<<i;
    //         cout<<endl;
    //         x=(!x);
    //     }
    // }
}


/*

1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
17 18 19 20
21 22 23 24
25 26 27 28







*/
int main(){
    fastio()
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}