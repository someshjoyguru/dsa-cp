#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define vll vector<ll>
#define in(n) ll n; cin >> n;
#define sin(s) string (s); cin >> (s);
#define vin(v, n) vll (v)(n); f(i, 0, n) cin >> (v)[i];
#define all(v) (v).begin(), (v).end()
#define sort(v) sort(all(v));
#define pYES cout << "YES" << endl;
#define pNO cout << "NO" << endl;




void solve() {
    in(n)
    sin(s)
    sin(r)
    
    stack<char> st;
    st.push(s[0]);
    ll ops=0;
    f(i,1,n){
        // if (st.size()>0){
            while (st.size()>0 && s[i]!=st.top()){
                st.pop();
                st.push(r[ops]);
                ops++;
                i++;
                if (ops==n-1){
                    pYES
                    return;
                }
            }
        // }
        if (ops==n-1){
            pYES
            return;
        }
        st.push(s[i]);
    }
    pNO
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
