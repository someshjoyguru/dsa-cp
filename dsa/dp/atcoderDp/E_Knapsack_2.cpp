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

void print2d(vector<vll>& v){
    int n=v.size();
    int m=v[0].size();
    f(i,0,n){
        f(j,0,m){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

void solve(){
    in(n) in(w)
    vector<vll> vec;
    ll sum=0;
    f(i,0,n){
        vin(v,2);
        vec.push_back(v);
        sum+=v[1];
    }
    // print2d(vec);
    // here your states should be ind, val
    // cout<<sum<<endl;
    vector<vll> dp(n+1, vll(sum+1,-1));
    ll maxi=0;
    function<ll(ll,ll)> fa = [&](ll ind, ll k)->ll{
        if (ind==n) {
            if (dp[ind-1][k]<=w) maxi=max(maxi, k);
            return 0;
        }
        if (dp[ind][k]!=-1) return dp[ind][k];
        ll take=INT_MAX, notTake=INT_MAX;
        if (w-k>= vec[ind][1]) take = vec[ind][0]+ fa(ind+1,k+vec[ind][1]);
        notTake=fa(ind+1,k);
        dp[ind][k]=min(take, notTake);
        if (dp[ind][k]==w) maxi=max(maxi, k);
        return dp[ind][k];
    };
    ll r = fa(0,0);
    // print2d(dp);
    cout<<maxi;
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}