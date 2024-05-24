#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define  fastio() ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
 
#define f(n)for (ll z=0; z<n; z++)
#define f1(z,n)for (ll z=0; z<n; z++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define inv(v,n) vll v(n); f(n)cin>>v[z];
#define pura(v) v.begin(),v.end()
#define sort(v) sort(pura(v));

const int num = 1e7 + 7;
vector<int> p(num, -1);

void solve(){
    in(n);
    ll sum=0;
    if (n>num)sum=n/15-10,n=n%15+10*15;
    cout<<sum+p[n]<<endl;
}

int main(){
    fastio();
    int t=1;

    for (int i=4; i<num; i++){
        p[0]=0;
        p[1]=1; p[2]=2; p[3]=1;
        vector<int> a={1,3,6,10,15};
        for (auto x : a){
            if (i-x>=0)if (p[i]==-1)p[i]=p[i-x]+1; else p[i]=min(p[i],p[i-x]+1);
        }
    }
    cin >> t;
    while(t--)solve();
}