#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define f(i, a, b) for (ll(i) = (a); (i) < (b); (i)++)
#define vll vector<ll>
#define in(n) \
    ll n;     \
    cin >> n;
#define sin(s) \
    string(s); \
    cin >> (s);
#define vin(v, n) \
    vll(v)(n);    \
    f(i, 0, n) cin >> (v)[i];
#define all(v) (v).begin(), (v).end()
#define sort(v) sort(all(v));
#define pYES cout << "YES" << endl;
#define pNO cout << "NO" << endl;

void solve()
{
    in(n)in(m)
    vector<vll> a(n, vll(m));
    f(i, 0, n) f(j, 0, m) cin >> a[i][j];
        f(i, 0, n) f(j, 0, m)
            {
                ll q=0;
                ll fl=1; 
                if(i-1>=0)q=max(q,a[i-1][j]);
                if(j-1>=0)q=max(q,a[i][j-1]);
                if(i+1<n)q=max(q,a[i+1][j]);
                if(j+1<m)q=max(q,a[i][j+1]);
                
                if(i-1>=0 && a[i][j]<=a[i-1][j])fl=0;
                if(j-1>=0 && a[i][j]<=a[i][j-1])fl=0;
                if(i+1<n && a[i][j]<=a[i+1][j])fl=0;
                if(j+1<m && a[i][j]<=a[i][j+1])fl=0;
                if(fl==1) a[i][j]=q;
        }

    f(i, 0, n)
    {
        f(j, 0, m)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}