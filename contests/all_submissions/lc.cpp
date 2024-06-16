#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(i,a,b) for (ll (i)=(a); (i)<(b); (i)++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define sin(s) string (s); cin>>(s);
#define vin(v,n) vll (v)(n); f(i,0,n)cin>>(v)[i];
#define all(v) (v).begin(),(v).end()
#define sort(v) sort(all(v));
#define pYES cout<<"YES"<<endl;
#define pNO cout<<"NO"<<endl;

class Solution {
public:
    string clearDigits(string s) {
        sin(s)
        ll n=s.size();
        ll cnt=0;
        string t;
        for (int i=n-1; i>=0; i--){
            if (s[i]>='1' && s[i]<='9'){
                cnt++;
            }
            if (cnt==0)t+=s[i];
        }
        reverse(all(s));
        return s;
    }
};