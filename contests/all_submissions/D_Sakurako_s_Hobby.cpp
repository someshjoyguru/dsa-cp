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
    in(n)
    vll p(n), F(n);
    f(i,0,n){
        cin >> p[i];
        p[i]--;
    }
    sin(s)

    vector<bool> vis(n, false);
    
    f(i,0,n){
        if (!vis[i]) {
            int j = i;
            vll c;
            while (!vis[j]) {
                vis[j] = true;
                c.push_back(j);
                j = p[j];
            }
            
            int bcnt = 0;
            for (int x : c) {
                if (s[x] == '0') {
                    bcnt++;
                }
            }
            
            for (int x : c) {
                F[x] = bcnt;
            }
        }
    }

    f(i,0,n){
        cout << F[i] << " ";
    }
    cout << endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}