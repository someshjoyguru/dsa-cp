#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n;cin>>n;
    if (n*(n+1)%4) {
        cout<<"NO"<<endl;
        return;
    }
    vector<ll> a,b;
    a.push_back(n);
    bool x= true;
    for (ll i=n-1; i>=1; i--){
        if (x) {
            b.push_back(i);
            if (i>1) b.push_back(i-1);
        }
        else{
            a.push_back(i);
            if (i>1) a.push_back(i-1);
        }
        i--;
        x=(!x);
    }
    cout<<"YES"<<endl;
    cout<<a.size()<<endl;
    for (auto i: a)cout<<i<<" ";
    cout<<endl;
    cout<<b.size()<<endl;
    for (auto i: b)cout<<i<<" ";
    // 7 4 3
    // 6 5 2 1
    // Remember:
    // 1) take from n to 1
    // 2) rectangular wave pattern (no 4 divisibility)
}

int main(){
    fastio()
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}