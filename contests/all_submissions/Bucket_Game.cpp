#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(i,a,b) for (ll (i)=(a); (i)<(b); (i)++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define sin(s) string (s); cin>>(s);
#define inv(v,n) vll (v)(n); f(i,0,n)cin>>(v)[i];
#define all(v) (v).begin(),(v).end()
#define sort(v) sort(all(v));

void solve(){
    in(n);
    inv(v,n);
    ll a=0, b=0;
    ll tot=0;
    ll cnt=0;
    bool turn = true;
    f(i,0,n){
        if (v[i]==1){
            if (turn) a++;
            else b++;
            turn=(!turn);
            v[i]--;
        }else if (v[i]>2){
            tot+=(v[i]-2);
            cnt++;
        }else cnt++;
    }
    if (tot%2) turn=(!turn);
    if (turn) b+=cnt;
    else a+=cnt; 
    
    if (a<b) cout<<"Bob"<<endl;
    else if (a>b) cout<<"Alice"<<endl;
    else cout<<"Draw"<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}