#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(i,a,b) for (ll (i)=(a); (i)<(b); (i)++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define sin(s) string (s); cin>>(s);
#define inv(v,n) vll (v)(n); f(i,0,n)cin>>(v)[i];
#define all(v) (v).begin(),(v).end()
#define sort(v) sort(all(v));

void solve(){
    in(p) in(s)
    vector<vll> v(2,vll(s,0));
    vector<vll> ans;
    // {n, i}
    f(r,0,p){
        f(i,0,2){
            f(j,0,s){
                cin>>v[i][j];
            }
        }
        vector<pair<ll,ll>> temp;
        f(q,0,s) temp.push_back({v[0][q], v[1][q]});
        sort(temp);
        ll score=0;
        f(q,0,s-1) if (temp[q].second>temp[q+1].second) score++;
        ans.push_back({score, r});
    }
    sort(ans);
    f(i,0,p) cout<<ans[i][1]+1<<endl;
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}