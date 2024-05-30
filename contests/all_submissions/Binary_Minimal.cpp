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
#define sort(v) sort(all(v));

void solve(){
    in(n) in(k)
    ll op=k;
    sin(s)
    ll cnt=0;
    f(i,0,n) if(s[i]=='1') cnt++;
    if (cnt>k){
        f(i,0,n){
            if (k>0 && s[i]=='1'){
                s[i]='0';
                k--;
            }else if (k==0) break;
        }
        cout<<s;
    }else f(i,0,n-k) cout<<'0';
    cout<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}