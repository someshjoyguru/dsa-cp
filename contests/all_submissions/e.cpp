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

string func(int N, int W, int R, vll& weights) {
    if (abs(R) >= W) {
        return "waku waku";
    }
    
    int ls = 0;
    int rs= 0;
    for (int wt : weights) {
        if (wt < 0) {
            ls += abs(wt);
        } else {
            rs += wt;
        }
    }
    
    if ( ls >= W && ls == rs) {
        return "waku waku";
    } else {
        return "orewa kanashii desu";
    }
}

void solve(){
    in(n) in(w) in(r)
    vin(weights,n)
    cout <<func(n, w,r, weights)<< endl;
}


int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}

