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

ll fa(ll i, ll j, string& r, string& s, ll n, ll m, vector<vector<ll>>& dp){
    if (i==n || j==m) return 0;
    string s1, s2;
    if (dp[i][j]!=-1) return dp[i][j];
    if (r[i]==s[j]) return dp[i][j]=1+fa(i+1,j+1,r,s,n,m,dp);
    return dp[i][j]=max(fa(i,j+1,r,s,n,m,dp), fa(i+1,j,r,s,n,m,dp));
}
void solve(){
    sin(r) 
    sin(s)
    vector<vector<ll>> dp(r.size()+1, vector<ll>(s.size()+1,-1));
    dp[0][0] = fa(0,0,r,s,r.size(), s.size(), dp);
    f(i,0,r.size()){
        f(j,0,s.size()){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    ll i=0, j=0;
    string ss;
    while (i<r.size() && j<s.size()){
        if (r[i]==s[j]){
            cout<<s[j];
            i++; j++;
        }else {
            if (i+1<r.size() && dp[i+1][j]==dp[i][j]) i++;
            else j++;
        }
    }
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}