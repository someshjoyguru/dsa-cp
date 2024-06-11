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
    in(n) in(w)
    vector<vll> vec;
    f(i,0,n){
        vin(v,2);
        vec.push_back(v);
    }
    vector<vll> dp(n, vll(w+1,-1));
    function<ll(ll,ll)> fa = [&](ll ind, ll k)->ll{
        if (ind==n) return 0;
        if (dp[ind][k]!=-1) return dp[ind][k];
        ll take=0, notTake=0;
        if (k>= vec[ind][0]) take = vec[ind][1]+ fa(ind+1,k-vec[ind][0]);
        notTake=fa(ind+1,k);
        return dp[ind][k]=max(take, notTake);
    };
    cout<<fa(0,w);
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}