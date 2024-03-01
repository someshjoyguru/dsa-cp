#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
    ll n; cin>>n;
    ll ans = pow(2,floor(log2(n)));
    cout << fixed << setprecision(0) << ans<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;    
    while(t--)solve();
}