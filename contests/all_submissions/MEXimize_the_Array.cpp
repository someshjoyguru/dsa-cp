#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(i,a,b) for (ll (i)=(a); (i)<(b); (i)++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define inv(v,n) vll v(n); f(n)cin>>v[z];
#define all(v) (v).begin(),(v).end()
#define sort(v) sort(pura(v));


void solve(){
    in(n);
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    f(i,0,n){
        ll x;
        cin>>x;
        pq.push(x);
    }
    ll ans=0;
    f(i,0,n){
        ll it = pq.top();
        pq.pop();
        ans+=(abs(it-i));
    }
    cout<<ans<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}