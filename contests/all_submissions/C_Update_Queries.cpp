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

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<pair<int, char>> updates(m);
    
    for (int i = 0; i < m; ++i) {
        cin >> updates[i].first;
        --updates[i].first; // converting to 0-based index
    }
    
    for (int i = 0; i < m; ++i) {
        cin >> updates[i].second;
    }
    
    // Sort updates by index, and by character lexicographically within the same index
    sort(updates.begin(), updates.end());
    
    // Apply the updates
    for (auto &upd : updates) {
        s[upd.first] = upd.second;
    }
    
    cout << s << '\n';
}


int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}