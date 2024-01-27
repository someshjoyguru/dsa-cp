#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    int n;
    cin>>n;
    for (int i=0; i<(1<<n);i++){
        string s;
        // for (int j=n-1; j>=0; j--){
        //     s+=to_string((i>>j)&1);
        // }
        for (int j=n-1; j>=0; j--){
            s+=to_string((i&(1<<j))?1:0);
        }
        cout<<s[0];
        for (int j=1; j<n; j++){
            cout<<(s[j]!=s[j-1]);
        }
        cout<<endl;
    }
//     cout<<"rough"<<endl;
//     cout<<(5&(1<<0))<<endl;
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