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
#define pYES cout<<'YES'<<endl;
#define pNO cout<<'NO'<<endl;

void solve(){
    in(k)
    // 1->9
    // 2->90
    // 3->900
    ll v=0;
    ll m=9;
    ll i=1;
    while(1){
        if (v+i*m>=k){
            ll left=k-v-1;
            ll val = left/i;
            string s=to_string((ll)pow(10,i-1)+val);
            cout<<s[left%i]<<endl;
            return;
        }else{
            v=v+(i*m);
            m=m*10;
            i++;
        }
        // cout<<v<<" "<<i<<" "<<m<<endl;
    }
    return;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}