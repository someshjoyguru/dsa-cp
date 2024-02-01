#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll m;cin>>m;
    multiset<ll> st;
    set<ll> temp;
    set<ll> sum;
    while(m--){
        for (auto x : st)cout<<x<<" ";
        cout<<endl;
        for (auto x : sum)cout<<x<<" ";
        cout<<endl;
        
        ll t,v;
        cin>>t>>v;
        if (t==1){
            st.insert(1<<v);
            ll x = (1<<v);
            sum.insert(x);
            for (auto i : sum){
                temp.insert(i+=x);
            }
            for (auto j : temp){
                sum.insert(j);
            }
        }else{
            if (sum.find(v)==sum.end()) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
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

/*

ADD x 
GET w


7
1 0
1 1
1 2
1 10
2 4
2 6
2 7

*/