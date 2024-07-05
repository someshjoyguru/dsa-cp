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
    
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}

#define ll long long
#define vll vector<ll>
class Solution {
public:
    static const int INV = 400;
    static const int MOD = 1e9+7;

    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        map<int, int> mp;
        for (auto x : requirements) {
            mp[x[0] + 1] = x[1]; 
        }

        vector<vll> dp(n + 1, vll(INV + 1, 0));
        dp[0][0] = 1;

        int l = 1;
        while (l <= n) {
            int inv = 0;
            while (inv <= INV) {
                int pos = 0;
            while (pos < l) {
                    int prev = inv - pos;
                    if (prev >= 0) {
                        dp[l][inv] = (dp[l][inv] + dp[l - 1][prev]) % MOD;
                    }
                    pos++;
                }
                inv++;
            }

            if (mp.count(l) > 0) {
                int inv = 0;
                int req = mp[l];
                while (inv <= INV) {
                    if (inv != req) {
                        dp[l][inv] = 0;
                    }
                    inv++;
                }
            }

            l++;
        }

        ll res = 0;
        int inv = 0;
        while (inv <= INV) {
            res = (res + dp[n][inv]) % MOD;
            inv++;
        }

        return res%MOD;
    }
};