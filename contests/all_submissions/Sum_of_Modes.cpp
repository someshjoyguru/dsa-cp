#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(n)for (ll z=0; z<n; z++)
#define f1(z,n)for (ll z=0; z<n; z++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define inv(v,n) vll v(n); f(n)cin>>v[z];
#define pura(v) v.begin(),v.end()
#define sort(v) sort(pura(v));

void solve(){
    in(n);
    string s; cin>>s;
    int ans=0;
    map<string,int> mp;
    for (int i=0; i<n; i++){
        int one=0, zero=0;
        for (int j=i; j<n; j++){
            if (s[j]=='0') zero++;
            else one++;
            if (mp.find(s.substr(i,j-i+1))==mp.end()){
                mp[s.substr(i,j-i+1)]++;
                if (zero==one) ans+=2;
                else ans++;
                cout<<s.substr(i,j-i+1)<<" "<<ans<<endl;
            }
        }
    }
    for (auto [a,b] : mp){
        cout<<a<<" "<<b<<endl;
    }
    cout<<ans<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}