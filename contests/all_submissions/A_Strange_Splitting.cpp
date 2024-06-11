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
    vin(v,n)
    bool fl=true;;
    for(int i=n-1; i>=0; i--){
        if (v[i]!=v[0]){
            pYES
            if (i==n-1){
                f(j,0,n-2)cout<<'R';
                cout<<"BR"<<endl;
                return;
            }
            f(j,0,i+1)cout<<'R';
            f(j,i+1,n)cout<<'B';
            cout<<endl;
            return;
        }
    }
    pNO
    // if (v[n-2]!=v[0]){
    //     pYES
    //     f(i,0,n-1)cout<<'R';
    //     cout<<'B'<<endl;
    // }

}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}