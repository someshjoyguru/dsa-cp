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

ll dp[1<<5000];

void solve(){
    in(n);
    inv(a,n);
    ll sum=0;
    ll mod=998244353;
    for (int i = 0; i < n; i++) {
        dp[1 << i] = a[i];
    }
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                dp[i] = max(dp[i], dp[i ^ (1 << j)] + a[j]);
            }
        }
        sum += dp[i];
        sum %= mod;
    }
    for (int i=0; i<(1<<n); i++){
        ll maxi=0;
        ll temp=0;
        for (int j=0; j<n; j++){
            if (i&(1<<j)){
                maxi=max(maxi,a[j]);
                temp+=a[j];
            }
        }
        maxi=max(maxi,temp/2+temp%2);
        sum+=maxi;
        sum%=mod;
    }
    cout<<sum%mod<<endl;
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}