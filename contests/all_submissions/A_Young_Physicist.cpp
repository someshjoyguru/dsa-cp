#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n;
    cin >> n;
    ll x=0,y=0,z=0;
    while(n--){
        ll a,b,c;
        cin >> a >> b >> c;
        x+=a;
        y+=b;
        z+=c;
    }
    if(x==0 && y==0 && z==0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}