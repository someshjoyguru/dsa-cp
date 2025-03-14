#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cerr.rdbuf(cout.rdbuf());
#define f(i,a,b) for (ll (i)=(a); (i)<(b); (i)++)
#define rf(i,a,b) for (ll (i)=(a); (i)>=(b); (i)--)
#define vll vector<ll>
#define vvll vector<vll>
#define in(n) ll n; cin>>n;
#define sin(s) string (s); cin>>(s);
#define vin(v,n) vll (v)(n); f(i,0,n)cin>>(v)[i];
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sort(v) sort(all(v));
#define rsort(v) sort(v) reverse(all(v));
#define pYES cout<<"YES\n";
#define pNO cout<<"NO\n";
const ll mod = 1000000007;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

template <typename T>
void _print(T x) { cerr << x; }
template <typename T, typename V>
void _print(pair<T, V> p) { cerr << "{"; _print(p.first); cerr << ", "; _print(p.second); cerr << "}"; }
template <typename T>
void _print(vector<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <typename T>
void _print(set<T> s) { cerr << "{ "; for (T i : s) { _print(i); cerr << " "; } cerr << "}"; }
template <typename T, typename V>
void _print(map<T, V> m) { cerr << "{ "; for (auto i : m) { _print(i); cerr << " "; } cerr << "}"; }
/* *********************Template ends here************** */

void solve() {
    in(n) in(m)
    vector<string> v;
    f(i,0,n){
        sin(s)
        v.push_back(s);
    }
    vvll es(n,vll(m,0));
    f(i,0,n){
        f(j,0,m){
            if (j==0 && v[i][j]=='L'){
                es[i][j]=1;
            }else if (j==m-1 && v[i][j]=='R'){
                es[i][j]=1;
            }else if (i==0 && v[i][j]=='U'){
                es[i][j]=1;
            }else if (i==n-1 && v[i][j]=='D'){
                es[i][j]=1;
            }
        }
    }
    queue<vll> q;
    f(i,0,n){
        f(j,0,m){
            if (es[i][j]==1){
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        if (it[0]>0 && v[it[0]-1][it[1]]=='D' && es[it[0]-1][it[1]]==0){
            es[it[0]-1][it[1]]=1;
            q.push({it[0]-1,it[1]});
        }
        if (it[0]<n-1 && v[it[0]+1][it[1]]=='U' && es[it[0]+1][it[1]]==0){
            es[it[0]+1][it[1]]=1;
            q.push({it[0]+1,it[1]});
        }
        if (it[1]>0 && v[it[0]][it[1]-1]=='R' && es[it[0]][it[1]-1]==0){
            es[it[0]][it[1]-1]=1;
            q.push({it[0],it[1]-1});
        }
        if (it[1]<m-1 && v[it[0]][it[1]+1]=='L' && es[it[0]][it[1]+1]==0){
            es[it[0]][it[1]+1]=1;
            q.push({it[0],it[1]+1});
        }
    }
    ll cnt=0;
    f(i,0,n)f(j,0,m){
        bool fl=true;
        if (v[i][j]=='?'){
            if (i>0 && es[i-1][j]==0) fl=false;
            else if (i<n-1 && es[i+1][j]==0) fl=false;
            else if (j>0 && es[i][j-1]==0) fl=false;
            else if (j<m-1 && es[i][j+1]==0) fl=false;
            if (fl) cnt++;
        }
        cnt+=es[i][j];
    }
    cout<<m*n-cnt<<endl;
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}