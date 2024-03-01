#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(){
  ll n; cin>>n;
  string s;
  vector<ll> a(n,0);
  for (ll i=0; i<n;i++){
    cin>>s;
    for (ll j=0; j<n; j++){
        if (s[j]=='1')a[j]++;
    }
  }



//   for (auto x: a){
//     cout<<x<<" ";
//   }
//   cout<<endl;
  for (ll i=0; i<n; i++){
    if (a[i]!=0){
        if (i>0){
            if (a[i]==a[i-1]){
                cout<<"SQUARE"<<endl;
                return;
            }
        }
        if (i<n-1){
            if (a[i]==a[i+1]){
                cout<<"SQUARE"<<endl;
                return;
            }
        }
    }
  }
  cout<<"TRIANGLE"<<endl;
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
}