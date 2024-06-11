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
    string s = to_string(n);
    f(i,0,s.size()){
        if (i==s.size()-1){
            if (s[i]=='9'){
                pNO
                return;
            }
        }else if(i==0){
            if (s[i]!='1'){
                pNO
                return;
            }
        }else{
            if (s[i]=='0'){
                pNO
                return;
            }
        }
    }
    pYES
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}