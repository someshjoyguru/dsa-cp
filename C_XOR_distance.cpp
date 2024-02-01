#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll a,b,r;
    cin>>a>>b>>r;
    // bitset<20> ax(a);
    // bitset<20> bx(b);
    // bitset<20> rx(r);
    // cout<<ax<<endl;
    // cout<<bx<<endl;
    // cout<<rx<<endl;
    ll i=0, j=1e18,mid,res;
    ll mini= abs((a-b))^0;
    while (i<j){
        mid=i+(j-i)/2;
        res = abs(a-b)^mid;
        if (res>mini){
            j=mid-1;
        }else{
            i=mid+1;
            mini=res;
        }
    }
    cout<<mini<<endl;
}

int main(){
    fastio()
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}