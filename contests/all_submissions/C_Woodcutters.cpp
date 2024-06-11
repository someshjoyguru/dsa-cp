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

ll func(ll ind, ll prev, ll dest, vector<vll>& vec, vector<vll>& dp){
    //base case
    if (ind==dest) return 0;
    if (dp[ind][prev]!=-1) return dp[ind][prev];
    ll left=0, right=0, still=0;
    if (prev==0){
        if (ind>0 && vec[ind][0]-vec[ind-1][0]>vec[ind][1]){
            left= 1 + func(ind+1, 0, dest,vec, dp);
        }else if (ind==0){
            left= 1 + func(ind+1, 0, dest,vec, dp);
        }
        still = 0 + func(ind+1, 0, dest, vec, dp);
        if (ind<dest-1 && vec[ind+1][0]-vec[ind][0]>vec[ind][1]){
            right= 1 + func(ind+1, 1, dest,vec, dp);
        }else if (ind==dest-1){
            right= 1 + func(ind+1, 1, dest,vec, dp);
        }
    }else{
        if (ind>0 && vec[ind][0]-vec[ind-1][0]-vec[ind-1][1]>vec[ind][1]){
            left= 1 + func(ind+1, 0, dest,vec, dp);
        }else if (ind==0){
            left= 1 + func(ind+1, 0, dest,vec, dp);
        }
        still = 0 + func(ind+1, 0, dest, vec, dp);
        if (ind<dest-1 && vec[ind+1][0]-vec[ind][0]-vec[ind-1][1]>vec[ind][1]){
            right= 1 + func(ind+1, 1, dest,vec, dp);
        }else if (ind==dest-1){
            right= 1 + func(ind+1, 1, dest,vec, dp);
        }
    }
    return dp[ind][prev]=max({left, right, still});
}
void solve(){
    in(n)
    vector<vll> vec(n, vll(2,0));
    f(i,0,n){
        cin>>vec[i][0]>>vec[i][1];
    }
    // prev=0 (signifies not fall or left fall)
    // prev=1 {signifies right fall}

    // f(i,0,n){
    //     cout<<vec[i][0]<<" "<<vec[i][1]<<endl;
    // }
    vector<vll> dp(n,vll(2,-1));
    cout<<func(0,0,n,vec, dp);
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}