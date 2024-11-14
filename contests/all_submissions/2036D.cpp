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
    in(n) in(m)
    vector<string> v;
    f(i,0,n){
        sin(s)
        v.push_back(s);
    }
    vector<string> lay;

    int x = min(n, m) / 2;
    f(k, 0, x) {
        string l;
        f(j, k, m - k) l += v[k][j];
        f(i, k + 1, n - k) l += v[i][m - k - 1];
        if (n - k - 1 > k) for (int j = m - k - 2; j >= k; j--) l += v[n - k - 1][j];       
        if (m - k - 1 > k) for (int i = n - k - 2; i > k; i--) l += v[i][k];
        l+=l.substr(0,3);
        lay.push_back(l);
    }
    ll c=0;
    for (string s : lay) {
        // cout << l << endl;
        ll cc=0;
        ll p=s.find("1543");
        while(p!=-1){
            cc++;
            p=s.find("1543",p+4);
        }
        c+=cc;
    }
    cout<<c<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}