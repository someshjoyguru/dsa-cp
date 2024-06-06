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
#define pYES cout<<"YES"<<endl;
#define pNO cout<<"NO"<<endl;

void solve(){
    in(n) in(k)
    vin(v,n)
    ll ans=0;
    f(i,0,n-1){
        ans+=(abs(v[i]-v[i+1]));
    }
    ll temp=ans;
    ll maxi=ans;
    f(i,0,n){
        temp=ans;
        //change it
        // badhake
        if (i>0){
            temp-=(abs(v[i-1]-v[i]));
            temp+=(abs(v[i-1]-k));
        }
        if (i<n-1){
            temp-=(abs(v[i+1]-v[i]));
            temp+=(abs(v[i+1]-k));
        }
        maxi=max(maxi, temp);
        //ghateke
        temp=ans;
        if (i>0){
            temp-=(abs(v[i-1]-v[i]));
            temp+=(abs(v[i-1]-1));
        }
        if (i<n-1){
            temp-=(abs(v[i+1]-v[i]));
            temp+=(abs(v[i+1]-1));
        }
        maxi=max(maxi, temp);
    }
    cout<<maxi<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}