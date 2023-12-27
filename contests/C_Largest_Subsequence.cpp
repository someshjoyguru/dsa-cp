#include <bits/stdc++.h>
using namespace std;
#define ll long long

string cycle(string s){
    int ind=0;
    string maxi = "a";
    for (int i=0; i<s.size(); i++){
        if (s[i]>=maxi[0]){
            maxi[0]=s[i];
            ind=i;
        }
    }
    for (int i=ind; i<s.size(); i++){
        if (i==ind){
            swap(s[i],s[0]);
        }
        swap(s[i],s[i+1]);

    }
}
void solve(){
    ll n;
    cin>>n;

}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}