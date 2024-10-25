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
    in(n) in(m)
    vector<vll> vec;
    f(i,1,n+1){
        sin(s)
        f(j,1,m+1){
            if (s[j-1]=='#'){
                vec.push_back({i,j});
            }
        }
    }
    ll x=0, y=0;
    ll cnt = vec.size();
    f(i,0,cnt){
        x+=vec[i][0];
        y+=vec[i][1];
    }
    x/=cnt;
    y/=cnt;
    cout<<x<<" "<<y<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}