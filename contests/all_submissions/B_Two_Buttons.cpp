#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


void solve(){
    ll n,m;
    cin>>n>>m;
    if (n>=m){
        cout<<n-m<<endl;
        return;
    }
    ll c=0;
    while(n!=m){
        if (n>=m){
            c+=(n-m);
            cout<<c<<endl;
            return;
        }else{
            if (m%2==0)m=m/2;
            else m++;
            c++;
        }
    }
    cout<<c<<endl;
    return;
}

/*
100
110
*/
int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}