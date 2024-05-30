#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(i,a,b) for (ll (i)=(a); (i)<(b); (i)++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define inv(v,n) vll (v)(n); f(i,0,n)cin>>(v)[i];
#define all(v) (v).begin(),(v).end()
#define sort(v) sort(pura(v));

void solve(){
    in(n);
    inv(v,n);
    ll add=INT_MAX;
    ll low=0, high=INT_MAX;
    ll i=0;
    while(i<n){
        if (v[i]<v[i-1]){
            if (i>0) low=max(low, v[i-1]-v[i]);
            if (i<n-1) {
                if (v[i]+low >v[i+1]){
                    cout<<"No"<<endl;
                    return;
                }
                high=min(high, v[i+1]-v[i]);
            }
            
            i+=2;
        }else{
            i++;
        }
    }
    if (low<=high){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}