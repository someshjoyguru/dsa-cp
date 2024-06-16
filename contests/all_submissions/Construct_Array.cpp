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
    if (n&1){
        cout<<-1<<endl;
        return;
    }
    ll c=1;
    f(i,0,n/2){
        if (i%2==0){
            cout<<c<<" ";
        }else{
            cout<<c*(-1)<<" ";
        }
        c++;
    }
    c--;
    f(i,n/2,n){
        if (i%2==0){
            cout<<c<<" ";
        }else{
            cout<<c*(-1)<<" ";
        }
        c--;
    }
    cout<<endl;
    // 1 -2 3 -3 2 -1
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}