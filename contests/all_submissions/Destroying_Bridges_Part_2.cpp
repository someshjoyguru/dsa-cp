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

void solve(){
    in(n) in(k)
    vll a(n);
    f(i,0,n) cin >> a[i];
    
    ll root = a[0];
    vll cost(a.begin() + 1, a.end());
    ll root_sum = 0;
    ll tot_rem_sm = 0;
    
    f(i,1,n){
        root_sum += (root * a[i]);
        tot_rem_sm += a[i];
    }
    
    if (root_sum <= k){
        cout << 1 << endl;
        return;
    }
    
    sort(cost.begin(), cost.end());
    
    ll cur_sm = 0;
    ll ans = n;
    f(i,0,cost.size()){
        cur_sm += cost[i];
        ll rem_sum = (tot_rem_sm - cur_sm);
        if(cur_sm * (rem_sum + root) <= k){
            ans = min(ans, n - (i + 1));
        }
    }
    
    cout << ans << endl;
}

int main(){
    fast;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
