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
    in(n)
    vin(a,n)
    in(m)
    vin(b,m)
    ll sum=0;
    ll maxi1=0, maxi2=0;
    ll pre=a[0], suf=a[n-1];
    f(i,0,n){
        if (i>0) pre+=a[i];
        maxi1=max(maxi1,pre);
    }
    maxi1=max(maxi1,pre);
    for (int i=n-1; i>=0; i--){
        if (i!=n-1) suf+=a[i];
        maxi2=max(maxi2,suf);
    }
    maxi2=max(maxi2,suf);
    sum+=max(maxi1,maxi2);
    f(i,0,m)if (b[i]>0)sum+=b[i];
    cout<<sum<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}