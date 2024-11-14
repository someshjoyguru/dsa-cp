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
    in(n)
    if (n==1){
        cout<<1<<" "<<1<<endl;
        return;
    }
    
    vll v(3*n,0);
    // f(i,0,3*n)cout<<v[i]<<" ";
    // cout<<endl;
    ll item=2;
    f(i,0,2*n){
        if (v[i]==0 && v[i+item]==0){
            v[i]=item;
            v[i+item]=item;
            item++;
        }
        if(item>n) break;
        // f(i,0,3*n)cout<<v[i]<<" ";
        // cout<<endl;
    }
    f(i,0,2*n-1){
        if (v[i]==0 && v[i+1]==0){
            v[i]=1; v[i+1]=1;
            break;
        }
    }
    f(i,0,2*n) if(v[i]==0){
        cout<<-1<<endl;
        return;
    }
    f(i,0,2*n)cout<<v[i]<<" ";
    cout<<endl;
    // cout<<endl;
    // cout<<endl;
    // cout<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}