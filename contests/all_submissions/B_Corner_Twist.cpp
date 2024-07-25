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
    in(n) in(m)
    vector<string> v(n), q(n);
    f(i,0,n)cin>>v[i];
    f(i,0,n)cin>>q[i];

    int cnt=0;
    f(i,0,n){
        int s1=0, s2=0;
        f(j,0,m){
            if (v[i][j]=='1')s1+=1;
            else if (v[i][j]=='2')s1+=2;
            if (q[i][j]=='1')s2+=1;
            else if (q[i][j]=='2')s2+=2;
        }
        if (s1%3!=s2%3){
            cout<<"NO"<<endl;
            return;
        }
    }
    f(i,0,m){
        int s1=0, s2=0;
        f(j,0,n){
            if (v[j][i]=='1')s1+=1;
            else if (v[j][i]=='2')s1+=2;
            if (q[j][i]=='1')s2+=1;
            else if (q[j][i]=='2')s2+=2;
        }
        if (s1%3!=s2%3){
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
/*
4 4
1020
1200
1210
0000

0000
1200
2200
0000

3 3
012
012
012

010
111
011

*/