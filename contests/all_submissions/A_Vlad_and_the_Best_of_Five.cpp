#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
4 1 2 3

*/
void solve(){
   string s;
   cin>>s;
   ll a=0,b=0;
   for (auto x:s){
    if (x=='A')a++;
    else b++;
   }
   if (a<b)cout<<"B"<<endl;
   else cout<<"A"<<endl;

}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
}