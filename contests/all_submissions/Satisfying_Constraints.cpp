#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n;
    cin>>n;
    ll left=1, right=1e9;
    set<ll> st;
    bool flag=false;
    for (ll i=0; i<n; i++){
        ll a,x;
        cin>>a>>x;
        if (a==1){
            if (x>left) left=x;
        }else if (a==2){
            if (x<right) right=x;
        }else{
            if (x>=left && x<=right)st.insert(x);
        }
        if (left>right){
            flag=true;
        }
    }
    set<ll> s;
    for (auto i: st){
        if (i>=left && i<=right)s.insert(i);
    }
    if (flag) cout<<0<<endl;
    else cout<<right-left-s.size()+1<<endl;
}

int main(){
    fastio()
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}