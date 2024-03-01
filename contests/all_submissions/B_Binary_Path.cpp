#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
    ll n; cin>>n;
    string s1, s2;
    cin>>s1>>s2;

    ll i = 1;
    ll j = 0;

    string ans = "";
    ll cnt = 1;
    ans += s1[0];

    while(i < n and j < n){
        if(s1[i] < s2[j]){
            ans += s1[i];
            i++;
            j++;
            cnt = 1;
        }else if(s1[i] == s2[j]){
            cnt++;
            ans += s1[i];
            i++;
            j++;
        }else{
            ans += s2[j];
            j++;
            break;
        }
    }
    while(j < n) ans += s2[j++];
    cout<<ans<<endl;
    cout<<cnt<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}