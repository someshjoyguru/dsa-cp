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
    sin(s)
    ll n=s.length();
    ll cntU=0;
    f(i,0,n){
        if (s[i]>='A' && s[i]<='Z') cntU++;
    }
    if(cntU>n-cntU){
        f(i,0,n){
            if (s[i]>='a' && s[i]<='z'){
                s[i]=(char)(s[i]-'a'+'A');
            }
        }
    }else{
        f(i,0,n){
            if (s[i]>='A' && s[i]<='Z'){
                s[i]=(char)(s[i]-'A'+'a');
            }
        }
    }
    cout<<s;
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}