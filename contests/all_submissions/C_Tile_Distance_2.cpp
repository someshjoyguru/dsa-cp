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

void solve(){
    in(sx) in(sy)
    in(dx) in(dy)
    // start brick
    ll startx1, startx2, destx1, destx2;
    if (sy%2){
        if (sx%2){
            startx1 = sx;
            startx2 = sx+2;
        }else{
            startx1 = sx-1;
            startx2 = sx+1;
        }
    }else{
        if (sx%2==0){
            startx1 = sx;
            startx2 = sx+2;
        }else{
            startx1 = sx-1;
            startx2 = sx+1;
        }
    }

    if (dy%2){
        if (dx%2){
            destx1 = dx;
            destx2 = dx+2;
        }else{
            destx1 = dx-1;
            destx2 = dx+1;
        }
    }else{
        if (dx%2==0){
            destx1 = dx;
            destx2 = dx+2;
        }else{
            destx1 = dx-1;
            destx2 = dx+1;
        }
    }
    
    if (dy==sy && startx1==destx1 && startx2==destx2){
        cout<<0;
        return;
    }

    ll diffy = abs(dy - sy);
    if (abs(startx1-destx2)<=diffy || abs(startx2-destx1)<=diffy){
        cout<<abs(dy-sy);
    }else{
        cout<<abs(dy-sy)+min(abs(startx1-destx2), abs(startx2-destx1));
    }
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}