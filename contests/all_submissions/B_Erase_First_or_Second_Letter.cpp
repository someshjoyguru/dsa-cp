#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n=0,flag=0,cnt=0,i=0,j,sum=0,k,q;
    cin>>n;
    string s;
    cin>>s;
    set <char> st;
    for(auto &i:s){
        st.insert(i);
        cnt+=st.size();
    }
    cout<<cnt<<"\n";
 
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}