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

int bit(int n){
  int cnt=0;
    while(n){
        n/=2; cnt++;
    }
    return cnt;
}
void solve(){
    in(n)
    vin(a,n) 
    vector<vll>v;
   
    vll bits(32,0);
    v.push_back(bits);
    f(i,0,n){
        int leftpos= bit(a[i]);
        bits[leftpos]++;
        v.push_back(bits);
    }
    ll k; cin>>k;
    while(k--){
        ll a,b,c; cin>>a>>b>>c;
        n=b-a+1;
        ll  idx=bit(c);
       
        cout<<n-((v[b][idx])-(v[a-1][idx]))<<"\n";
    }
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}