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
    vin(k,n)
    vll ans(n,1);
    bool fl=true;
    ll cost=n;
    while (true){
        f(i,0,n){
            while (true){
                ll x=0;
                if ((ans[i]+x)*k[i]<=cost+x){
                    fl=false;
                    x++;
                }else{
                    ans[i]+=x;
                    cost+=x;
                    break;
                }
                if (x>1000){
                    cout<<-1<<endl;
                    return;
                }
            }
        }
        if (fl==false){
            fl=true;
        }else break;
    }
    f(i,0,n)cout<<ans[i]<<" ";
    cout<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}