#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(i,a,b) for (ll (i)=(a); (i)<(b); (i)++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define sin(s) string (s); cin>>(s);
#define vin(v,n) vll (v)(n); f(i,0,n)cin>>(v)[i];
#define all(v) (v).begin(),(v).end()
#define sort(v) sort(all(v));
#define pYES cout<<'YES'<<endl;
#define pNO cout<<'NO'<<endl;

void solve(){
    in(n)
    vin(a,n)
    sort(a)


    vll v, v2;
    for (ll i=1; i<n; i+=2){
        v.push_back(a[i]-a[i-1]);
    }
    ll diff=1;
    sort(v)
    f(i,0,v.size()){
        diff=max(diff, v[i]);
    }


    if (n%2==0){
        cout<<diff<<endl;
        return;
    }


    for (ll i=2; i<n; i+=2){
        v2.push_back(a[i]-a[i-1]);
    }
    // for (auto c: v2)cout<<c<<" ";
    // cout<<endl;
    ll diff3=1e18;
    for (ll i=0; i<n; i+=2){
        ll tmp=1;
        for (ll j=1; j<i; j+=2){
            tmp=max(tmp,a[j]-a[j-1]);
        }
        for (ll j=i+2; j<n; j+=2){
            tmp=max(tmp,a[j]-a[j-1]);
        }
        diff3=min(diff3,tmp);
    }

    // ll diff1=1;
    // sort(v2)
    // f(i,0,v2.size()){
    //     diff1=max(diff1, v2[i]);
    // }
    cout<<diff3<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}