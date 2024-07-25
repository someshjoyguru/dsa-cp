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
    sin(s)
    sin(t)
    map<ll,ll> mp;
    f(i,0,n){
        mp[s[i]=='1']++;
        if (s[i]!=t[i]){
            if (t[i]=='1'){
                if (mp[1-(s[i]=='1')]>0){
                    mp[t[i]=='1']++;
                }else{
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"YES"<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}