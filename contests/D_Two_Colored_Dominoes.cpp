#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<string> s(n);
    for(auto &e: s)
        cin>>e;

    ll f = 0;

    for(ll i=0; i<n; i++)
    {
        ll cnt = 0;
        for(ll j=0; j<m; j++)
            cnt += (s[i][j] != '.');

        f |= (cnt%2);
    }

    for(ll j=0; j<m; j++)
    {
        ll cnt = 0;
        for(ll i=0; i<n; i++)
            cnt += (s[i][j] != '.');

        f |= (cnt%2);
    }

    if(f)
    {
        cout<<-1<<"\n";
        return;
    }


    vector<vector<ll>> ans(n, vector<ll> (m, -1));

    for(ll i=0; i<n-1; i++)
    {
        ll c = 0;

        for(ll j=0; j<m; j++)
        {
            if(s[i][j]=='U')
            {
                ans[i][j] = c;
                ans[i+1][j] = c^1;
                c ^= 1;
            }
        }
    }

    for(ll j=0; j<m-1; j++)
    {
        ll c = 0;

        for(ll i=0; i<n; i++)
        {
            if(s[i][j]=='L')
            {
                ans[i][j] = c;
                ans[i][j+1] = c^1;
                c ^= 1;
            }
        }
    }

    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            if(ans[i][j] == -1)     cout<<'.';
            if(ans[i][j] ==  1)     cout<<'B';
            if(ans[i][j] ==  0)     cout<<'W';
        }
        cout<<"\n";
    }

    
}

int main(){
    fastio()
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}