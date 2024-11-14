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

void vout(const vector<ll> &v) {
    for (auto &val : v) cout << val << " ";
    cout << endl;
}

void solve(){
    in(n) in(k) in(q)
    vector<vll> v(n, vll (k,0)), b(n, vll (k,0));
    f(i,0,n)f(j,0,k)cin>>v[i][j];

    f(j,0,k)b[0][j]=v[0][j];

    f(j,0,k)f(i,1,n){
        b[i][j]=(b[i-1][j]|v[i][j]);
    }
    // f(i,0,n)vout(b[i]);
    vector<vll> vv;
    f(i,0,k){
        vll tmp;
        f(j,0,n) tmp.push_back(b[j][i]);
        vv.push_back(tmp);
        // vout(tmp);
    }


    while(q--){
        in(m)
        ll mini=0, maxi=n-1;
        bool b=true;
        while(m--){
            in(r)
            char o; cin>>o;
            in(c)
            r--;
            if (o=='>') {
                auto it = upper_bound(vv[r].begin(), vv[r].end(), c);
                if (it == vv[r].end()) {
                    b = false;
                    break;
                }
                mini = max(mini, (ll)distance(vv[r].begin(), it));
            } else if (o == '<') {
                auto it = lower_bound(vv[r].begin(), vv[r].end(), c);
                if (it == vv[r].begin()) {
                    b = false;
                    break;
                }
                it--;
                maxi = min(maxi, (ll)distance(vv[r].begin(), it));
            }
        }
        if (!b || maxi < mini) cout << -1 << endl;
        else cout << mini + 1 << endl;
    }
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}