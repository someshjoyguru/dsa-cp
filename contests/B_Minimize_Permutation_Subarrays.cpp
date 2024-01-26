#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for (ll i=0; i<n; i++)cin>>v[i];
    ll i1,i2,in;
    // place n between 1 and 2
    // 3 case
    // 1 n 2
    // 2 n 1
    // n (1 2)
    // 
    for (ll i=0; i<n; i++){
        if (v[i]==1)i1=i+1;
        if (v[i]==2)i2=i+1;
        if (v[i]==n)in=i+1;
    }
    if ((i1<in && in<i2) || (i1>in && in>i2))cout<<1<<" "<<1<<endl;
    else {
        if (i1<in && i2<in){
            if (i1<i2)cout<<i2<<" "<<in<<endl;
            else cout<<i1<<" "<<in<<endl;
        }else{
            if (i1<i2)cout<<i1<<" "<<in<<endl;
            else cout<<i2<<" "<<in<<endl;
        }
    }
    // if (n%2)cout<<n/2+1<<" "<<i1+1<<endl;
    // else cout<<n/2<<" "<<i1+1<<endl;
    // for (ll i=0; i<n; i++){
    //     if (v[i]==1)i1=i;
    //     if (v[i]==n-1)i2=i;
    // }
    // 4 case
    // i1 -> 0, i1 ->n-1
    // i2 -> 0, i2 ->n-1
    // max(abs(i2-i1)) -> print
    // ll maxi = max({
    //     i2-0,
    //     n-1-i2,
    //     i1-0,
    //     n-1-i1
    // });
    // if (i2==maxi)cout<<1<<" "<<i1+1<<endl;
    // else if (i1==maxi)cout<<1<<" "<<i2+1<<endl;
    // else if (n-1-i2==maxi)cout<<n<<" "<<i1+1<<endl;
    // else if (n-1-i1==maxi)cout<<n<<" "<<i2+1<<endl;
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