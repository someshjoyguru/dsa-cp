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

ll ff(ll num) {
    if (num % 2 == 0) return 2;
    for (ll i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return i;
    }
    return num;
}

ll fff(ll num) {
    ll count = 0;
    
    while (num != 1) {
        ll div = ff(num);
        num /= div;                    
        count++;                           
    }
    
    return count;
}

void solve(){
    in(h) in(k)
    ll c=0;
    // while(k!=1){
    //     k/=2;
    //     c++;
    // }
    ll msb=0;
    f(i,0,64){
        if (k&(1<<i)){
            msb=i;
        }
    }
    // cout<<"msb "<<msb<<endl;
    // h=(ll)h*(ll)(1<<msb);
    // 110
    // c+=msb;
    c+=fff(h);
    ll nn=(ll)(1<<msb);
    c+=fff(nn);
    cout<<c<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}