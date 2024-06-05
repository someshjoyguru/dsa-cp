#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(i,a,b) for (ll (i)=(a); (i)<(b); (i)++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define vin(v,n) vll (v)(n); f(i,0,n)cin>>(v)[i];
#define all(v) (v).begin(),(v).end()

void solve(){
    in(n)
    fflush(stdout);
    in(k)
    fflush(stdout);
    ll s1, s2, s3, temp;
    
    cout<<"and 1 2"<<endl;
    fflush(stdout);
    cin>>s1;
    cout<<"or 1 2"<<endl;
    fflush(stdout);
    cin>>temp;
    s1+=temp;

    cout<<"and 2 3"<<endl;
    fflush(stdout);
    cin>>s2;
    cout<<"or 2 3"<<endl;
    fflush(stdout);
    cin>>temp;
    s2+=temp;

    cout<<"and 1 3"<<endl;
    fflush(stdout);
    cin>>s3;
    cout<<"or 1 3"<<endl;
    fflush(stdout);
    cin>>temp;
    s3+=temp;

    ll a2=(s1+s2-s3)/2;
    ll a1=s1-a2;
    ll a3=s2-a2;

    vll v(n);
    v[0] = a1;
    v[1] = a2;
    v[2] = a3;

    f(i,3,n){
        cout<<"and 1 "<<i+1<<endl;
        fflush(stdout);
        cin>>s2;
        cout<<"or 1 "<<i+1<<endl;
        fflush(stdout);
        cin>>temp;
        s2+=temp;
        v[i] = s2 - a1;
    }
    
    sort(all(v));
    cout<<"finish "<<v[k-1]<<endl;
    fflush(stdout);
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}
