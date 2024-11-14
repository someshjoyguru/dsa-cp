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
    sin(s)
    ll n=s.size();
    ll x=0, y=0;
    ll maxiX=0, miniX=1e9;
    ll maxiY=0, miniY=1e9;
    f(i,0,n){
        if (s[i]=='L'){
            x--; y--;
        }else if (s[i]=='R'){
            x++; y--;
        }else y++;
        miniX=min(miniX,x);
        miniY=min(miniY,y);
        maxiX=max(maxiX,x);
        maxiY=max(maxiY,y);
    }
    int N = 4;
    int A = 2;
    int B = 1;
    vector<pair<int, int>> tree(N + 1, {0, 0});
    tree[1] = {2, 0};
    tree[2] = {3, 4};
    tree[3] = {0, 0};
    tree[4] = {0, 0};

    cout << N << " " << A << " " << B << endl;
    for (int i = 1; i <= N; ++i) {
        cout << tree[i].first << " " << tree[i].second << endl;
    }

    return;
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}