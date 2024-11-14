#include   <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>


using namespace std;
// using namespace __gnu_pbds;

#define  retn            return
#define  ctnu            continue
#define  endl            '\n'
#define  pb              push_back
#define  ppb             pop_back
#define  rep(i,a,n)      for(ll i =a;i<n;i++)
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define  ss              second
#define  ff              first
#define  gcd             __gcd
#define  all(x)          x.begin(),x.end()
#define  printall(v)     for(auto value:v) cout<<value<<" ";cout<<endl;
#define  mp              make_pair
#define  PI              3.141592653589793238462643383279502884197
#define  ub              upper_bound
#define  lb              lower_bound
#define  read(v,n)       rep(i,0,n)cin>>v[i];
#define  count_set_bits  __builtin_popcountll



#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif


typedef long long int ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef pair<ll,ll>pll;
typedef map<ll,ll> mll;
typedef vector<vector<ll>> vvll;
typedef vector<pair<ll,ll>> vpll;
typedef vector<ld> vld;
typedef vector<char> vch;
typedef vector<vector<char>> vvch;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds;

ld eps = 1e-9;

/*
For using ordered_set : 

1. *s.find_by_order(k) --> Returns the element present at index k.

2.  s.order_of_key(k) -->  Returns the number of elements smaller than k.

Generate a random number from l to r:

 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); --> One time declaration of rng
 
 ll value = uniform_int_distribution<ll>(l,r)(rng); --> Declare value whenever want to generate a random number.
 
*/





void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}








void solve()

{
    ll n;
    cin>>n;
    vll v(n);
    read(v,n);

    sort(all(v));

    vll sum;

    rep(i,0,n-1)
    {
        sum.pb(v[i] + v[i+1]);
    }
    ll ans = n;
    debug(sum);
    for(ll i = n-1; i >= 0; i--)
    {
        ll cnt = (n-1-i);
        auto it = ub(sum.begin(), sum.begin() + (i-1), v[i]);
        it--;
        ll val = (it-sum.begin()+1);
        cnt += val;
        debug(val);
        ans = min(ans, cnt);
    }
    debug(ans);
    cout<<ans<<endl;
}










int main()
{
      #ifndef ONLINE_JUDGE
      freopen("Error.txt", "w", stderr);
      #endif

      fastio();
  
      ll t=1;
      //pre();

      cin>>t;
  
  
  
      for(ll ttt = 1;ttt<=t;ttt++)
      {
        
    
          //  cout<<"Case #"<<ttt<<": ";
    
    
        solve();
    
    
      }    
  
  
  
      return 0;
}