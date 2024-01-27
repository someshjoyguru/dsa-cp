#include <bits/stdc++.h>
using namespace std;
#define fastio()                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
#define ll long long

void solve()
{
    ll n, m;
    cin >> n >> m;
    string a,b;
    for (int i=0; i<1000; i++){
        a+='4';
        b+='5';
    }
    //45 -> 9
    //55 -> 1
    //100 -> 1
    cout<<a+'5'<<endl;
    cout<<b+'5'<<endl;
}

int main()
{
    fastio()
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}