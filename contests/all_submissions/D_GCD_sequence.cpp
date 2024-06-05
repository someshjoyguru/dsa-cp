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
    vll x;
    f(i,0,n-1){
        x.push_back(__gcd(v[i], v[i+1]));
    }
    ll br=-1;
    f(i,0,n-2){
        if (x[i+1]<x[i]){
            br=i+1;
            break;
        }
    }
    if (br!=-1){
        //remove i+1 check
        vll d;
        f(i,0,n-1){
            if (i+2<n && i==br-1) d.push_back(__gcd(v[i], v[i+2]));
            else if (i==br)continue;
            else d.push_back(__gcd(v[i], v[i+1]));
        }
        bool fl=true;
        f(i,0,n-1){
            if (d[i+1]<d[i]) {
                fl==false;
                break;
            }
        }
        if (fl) {
            pYES
            return;
        }
        //remove i+2 then check
        d.clear();
        br++;
        f(i,0,n-1){
            if (i+2<n && i==br-1) d.push_back(__gcd(v[i], v[i+2]));
            else if (i==br)continue;
            else d.push_back(__gcd(v[i], v[i+1]));
        }
        fl=true;
        f(i,0,n-1){
            if (d[i+1]<d[i]) {
                fl==false;
                break;
            }
        }
        if (fl) {
            pYES
            return;
        }
        pNO
    }else{
        pYES
    }

}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}