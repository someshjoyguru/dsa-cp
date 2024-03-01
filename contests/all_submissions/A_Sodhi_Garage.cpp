#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
   ll n; cin>>n;
   if (n<4){
    cout<<-1<<endl;
    return;
   }
  if (n%2){
      cout << -1 << endl;
    } else {
      cout << (n + 4) / 6 << ' ' << n/4 << endl;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
}