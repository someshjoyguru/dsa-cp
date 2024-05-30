#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(i,a,b) for (ll (i)=(a); (i)<(b); (i)++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define sin(s) string (s); cin>>(s);
#define inv(v,n) vll (v)(n); f(i,0,n)cin>>(v)[i];
#define all(v) (v).begin(),(v).end()
#define sort(v) sort(pura(v));

void solve(){
    in(n);
    sin(s);
    ll one=0,curz=0,maxz=0;
    f(i,0,n){
        if(s[i]=='1'){
            one++;
            curz=0;
        }
        else{
            curz++;
            maxz=max(maxz,curz);
        }
    }
    cout<<one+maxz<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}