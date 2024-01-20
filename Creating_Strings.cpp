#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    string s; cin>>s;
    sort(s.begin(),s.end());
    string flag = s;
    vector<string> v;
    v.push_back(s);
    while (true){
        next_permutation(s.begin(),s.end());
        if (s==flag)break;
        else v.push_back(s);
    }
    cout<<v.size()<<endl;
    for (auto i : v){
        cout<<i<<endl;
    }
    return;
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