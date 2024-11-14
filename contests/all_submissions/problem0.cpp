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

ll dist(ll a1, ll b1, ll a2, ll b2){
    return abs(a1-a2)+abs(b1-b2);
}

void solve(){
    in(n) in(m) in(r1) in(r2)
    if (n>m) swap(n,m);
    if (r1>r2)swap(r1,r2);
    ll a1=r1+1, b1=r1+1;
    ll a2=m-r2, b2=n-r2;
    if (a1 < 1 || a1 > m || b1 < 1 || b1 > n || a2 < 1 || a2 > m || b2 < 1 || b2 > n) {
        cout << -1 << endl;
        return;
    }
    // cout<<a1<<" "<<b1<<" "<<a2<<" "<<b2<<endl;
    // cout<<dist(a1,b1,a2,b2)<<endl;
    // cout<<a1<<endl;
    // cout<<b1<<endl;
    // cout<<<<endl;
    // cout<<<<endl;
    if (dist(a1,b1,a2,b2)<=r1+r2+1) cout<<-1<<endl;
    else {
        ll a2=a1+r1+r2+1;
        ll b2=r2+1;
        bool b=true;
        ll ans=1e9;
        while(b){
            if (dist(a1,b1,a2,b2)>r1+r2+1){
                if (b2>=1 && b2<=n && a2>=1 && a2<=m){
                    ans=min(ans,a2+b2);
                }
            }else b=false;
            a2--;
            b2++;
        }
        cout<<a1+b1+ans<<endl;
    }
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}