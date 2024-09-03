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
    in(n) sin(s)
    map<char, ll> e, o, all;
    

    for (int i=0; i<n; i+=2){
        e[s[i]]++;
        all[s[i]]++;
        if (i+1<n) o[s[i+1]]++;
        if (i+1<n) all[s[i+1]]++;
        
    }
    // if (n%2) o[s[n-1]]++;
    ll maxi1=0;
    ll maxi2=0;
    char maxi1ch, maxi2ch;
    for (auto ch: e){
        if (maxi1<ch.second){
            maxi1=max(maxi1, ch.second);
            maxi1ch=ch.first;
        }
    }
    for (auto ch: o){
        if (maxi2<ch.second){
            maxi2=max(maxi2, ch.second);
            maxi2ch=ch.first;
        }
    }
    for (auto ch: all){
        if (maxi2<ch.second){
            maxi2=max(maxi2, ch.second);
            maxi2ch=ch.first;
        }
    }
    
    
    // cout<<maxi1<<" "<<maxi2<<" "<<endl;
    if (n%2){
        for (int i=0; i<n; i+=2){
            if (i+1<n) all[s[i+1]]++;
            
        }
        ll maxi1=0;
        ll maxi2=0;
        
        for (auto ch: all){
            char c = ch.first;
            ll x=ch.second;
            if (x>maxi2){
                maxi2=x;
            }else if (x>maxi1){
                maxi1=x;
            }
        }
    } 
    else cout<<(n-maxi1-maxi2)<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}