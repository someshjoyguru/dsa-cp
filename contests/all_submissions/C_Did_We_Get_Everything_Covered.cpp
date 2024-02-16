#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n,k,m;
    cin>>n>>k>>m;
    string s; cin>>s;
    // n -> size of subseq
    // k -> variety
    // map<char,ll> mp;
    set<char> st;
    for (ll i=0; i<m; i++){
        st.insert(s[i]);
        if (st.size()==k){
            st.clear();
        }
    }
    if (st.empty())cout<<"YES"<<endl;
    else {
        for (ll i=0; i<k; i++){
            char x = 'a'+i;
            if (st.find(x)==st.end()){
                cout<<"NO"<<endl;
                for (ll i=0; i<k; i++){
                    cout<<x;
                }
                cout<<endl;
                return;
            }
        }
    }

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