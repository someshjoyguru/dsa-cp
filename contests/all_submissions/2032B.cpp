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
    in(n) in(k)
    if (n<4){
        if (k!=n/2+n%2){
            cout<<"-1"<<endl;
            return;
        }
        cout<<n<<endl;
        f(i,0,n)cout<<i+1<<" ";
        cout<<endl;
    }else{
        if (k==1 || k==n){
            cout<<"-1"<<endl;
            return;
        }
        if ((k-1)%2==0) cout<<"5\n1 2 "<<k<<" "<<k+1<<" "<<k+2<<endl;
        else cout<<"3\n1"<<" "<<k<<" "<<k+1<<endl;
    }
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}