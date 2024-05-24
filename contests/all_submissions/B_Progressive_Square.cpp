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
    ll n,c,d;
    cin>>n>>c>>d;
    inv(v,n*n);
    sort(v);
    vll a;
    // a.push_back(1);
    // ll temp=1;
    // for (ll i=1; i<n; i++){
    //     temp+=d;
    //     a.push_back(temp);
    // }
    // ll x=0;
    // temp=1;
    // for (ll i=n; i<n*n; i++){
    //     temp++;
    //     a.push_back(a[i%n + n*x]);
    //     if (temp==n){
    //         temp=1;
    //         x++;
    //     }
    // }
    vector<vector<ll>> mat(n, vector<ll>(n));
    mat[0][0]=*min_element(v.begin(),v.end());
    for (int i=1; i<n; i++){
        mat[0][i]=mat[0][i-1]+d;
    }
    for (int i=1; i<n; i++){
        for (int j=0; j<n; j++){
            mat[i][j]=mat[i-1][j]+c;
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            a.push_back(mat[i][j]);
        }
    }
    sort(a);
    for (int i=0; i<n*n; i++){
        if (v[i]!=a[i]){
            cout<<"NO"<<endl;
            return;
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