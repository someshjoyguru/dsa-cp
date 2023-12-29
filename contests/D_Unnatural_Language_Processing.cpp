#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

// void solve(){
//     ll n;
//     cin>>n;
//     string s;
//     cin>>s;
//     ll c=0, v=0;
//     for (ll i=0; i<n; i++){
//         if (s[i]=='b' || s[i]=='c' || s[i]=='d' ){
//             c++;
//         }else v++;
//     }
//     ll cvc = c-v;
//     string ans="";
//     for (ll i=0; i<n; ){
//         if (i+3<n){
//             if ((s[i+2]=='b' || s[i+2]=='c' || s[i+2]=='d' )&&(s[i+1]=='a'|| s[i+1]=='e')){
//                 ans+=s[i];
//                 ans+=s[i+1];
//                 ans+=s[i+2];
//                 ans+='.';
//                 i+=3;c-=2;v--;
//             }else if (s[i+1]=='a'|| s[i+1]=='e'){
//                 ans+=s[i];
//                 ans+=s[i+1];
//                 ans+='.';
//                 i+=2;c--;v--;
//             }   
//         }else{
//             if (i+2<n)
//             ans+=s[i];
//             ans+=s[i+1];
//             ans+='.';
//             i+=2;c--;v--;
//         }
//     }
// }

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    string ans;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]=='e' || s[i]=='a')
        {
            ans.push_back(s[i]);
            int j = i + 1;
            if (j == s.size() - 1){}
            else if (j + 1 <= s.size() - 1)
            {

                if ((s[j]=='b' || s[j]=='c' || s[j]=='d' ) && (s[j+1]=='b' || s[j+1]=='c' || s[j+1]=='d' ))
                {
                    ans.push_back(s[j]);
                    i = j;
                    ans.push_back('.');
                }
                else ans.push_back('.');
            }
        }
        else ans.push_back(s[i]);
    }
    cout << ans << endl;
}


int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}