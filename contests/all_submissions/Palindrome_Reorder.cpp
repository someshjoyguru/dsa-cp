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
#define pYES cout<<'YES'<<endl;
#define pNO cout<<'NO'<<endl;

void solve(){
    sin(s)
    ll n=s.size();
    map<char,ll> mp;
    f(i,0,n)mp[s[i]]++;
    ll c=0;
    char k='A';
    string ss = string(n,'A');
    ll i=0;
    for (auto it: mp){
        if (it.second%2){
            c++;
            k=it.first;
            if (c>1){
                cout<<"NO SOLUTION";
                return;
            }
        }
        ll cnt=it.second/2;
        while(cnt--){
            ss[i]=it.first;
            ss[n-i-1]=it.first;
            i++;
        }
    }
    if (n%2) ss[n/2]=k;
    cout<<ss;
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}