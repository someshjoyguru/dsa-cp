#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(n)for (ll z=0; z<n; z++)
#define f1(z,n)for (ll z=0; z<n; z++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define inv(v,n) vll v(n); f(n)cin>>v[z];
#define pura(v) v.begin(),v.end()
#define sort(v) sort(pura(v));


#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int cnta[1000100], cntb[1000100];

ll solve1(int n, int m, int k, VI& a, VI& b){
    // int n, m, k;
    // cin >> n >> m >> k;
    // VI a(n), b(m);
    // rep(i, n) cin >> a[i];
    // rep(i, m) cin >> b[i];
    for (int x : b) cntb[x]++;
    int now = 0;  // sum min(cntbi, cntai)
    rep(i, m - 1) {
      int x = a[i];
      now -= min(cnta[x], cntb[x]);
      cnta[x]++;
      now += min(cnta[x], cntb[x]);
    }
    int ans = 0;
    rep(i, n - m + 1) {
      {
        int x = a[i+m-1];
        now -= min(cnta[x], cntb[x]);
        cnta[x]++;
        now += min(cnta[x], cntb[x]);
      }
      ans += now >= k;
      {
        int x = a[i];
        now -= min(cnta[x], cntb[x]);
        cnta[x]--;
        now += min(cnta[x], cntb[x]);
      }
    }
    for (int x : a) cnta[x] = 0;
    for (int x : b) cntb[x] = 0;
    return ans;
}




ll solve(int n, int m, int k, VI& a, VI& b){
    // ll n,m,k;
    // cin>>n>>m>>k;
    // inv(a,n);
    // inv(b,m);
    map<ll,ll> mp1, mp2;
    ll l=0, r=m-1;
    for (int i=0; i<m; i++){
        mp1[b[i]]++;
    }
    ll temp=0;
    
    for (int i=0; i<m; i++){
        if (mp1.find(a[i])!=mp1.end()){
            mp2[a[i]]++;
            temp++;
        }
    }
    ll ans=0;
    if (mp2.size()>=k){
        ans++;
    }
    for (int i=1; i<=n-m; i++){
        if (mp2.find(a[i-1])!=mp2.end()){
            mp2[a[i-1]]--;
            temp--;
            if (mp2[a[i-1]]==0){
                mp2.erase(a[i-1]);
            }
        }
        
        if (mp1.find(a[i+m-1])!=mp1.end()){
            mp2[a[i+m-1]]++;
            temp++;            
        }
        if (mp2.size()>=k)ans++;
    }
    return ans;
}

void generateRandomInputs() {
    // Generate random values for n, m, and k
    ll n = rand() % 200000 + 1; // Adjust range as needed
    ll m = rand() % 200000 + 1; // Adjust range as needed
    ll k = rand() % 200000 + 1; // Adjust range as needed
    
    VI a, b;
    // Generate random values for arrays a and b
    a.clear();
    b.clear();
    for (int i = 0; i < n; ++i) {
        a.push_back(rand() % 1000000 + 1); // Adjust range as needed
    }
    for (int i = 0; i < m; ++i) {
        b.push_back(rand() % 1000000 + 1); // Adjust range as needed
    }
    // cout<<"n="<<n<<" m="<<m<<" k="<<k<<endl;

    if (solve(n, m, k, a, b) != solve1(n, m, k, a, b)) {
        cout << "Failed for n = " << n << ", m = " << m << ", k = " << k << endl;
        cout << "a = ";
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
        cout << "b = ";
        for (int i = 0; i < m; ++i) {
            cout << b[i] << " ";
        }
        cout << endl;
    }
}

int main(){
    fast;
    srand(time(NULL));
    ll t=100000000;
    // cin >> t;
    while(t--)generateRandomInputs();
}