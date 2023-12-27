#include <bits/stdc++.h>
using namespace std;
#define ll long long

void li(vector<ll> h,
        vector<ll> &lh,
        ll n)
{
    stack<ll> st;

    for (ll i = 0; i < n; i++)
    {
        while (st.empty() == false && h[st.top()] < h[i])
            st.pop();

        lh[i] = (st.empty() == false) ? st.top() : (-1);
        st.push(i);
    }

    return;
}

void solve()
{
    ll n, h0, a, c, q;
    cin >> n >> h0 >> a >> c >> q;
    if (n == 1)
    {
        cout << 0;
        return;
    }
    vector<ll> h(n);
    h[0] = h0;
    for (ll i = 1; i < n; i++)
    {
        h[i] = (h[i - 1] * a + c) % q;
    }
    ll ans = 0;
    // vector<ll> dp(n,0);
    // for (ll i=1; i<n; i++){
    //     if (h[i]>=h[i-1])dp[i]=1;
    // }
    vector<ll> lh(n);
    li(h, lh, n);

    // for (ll i=0; i<n; i++){
    //     cout<<lh[i]<<" ";
    // }
    for (ll i = 0; i < n; i++)
    {

        ll l_index = lh[i];

        if (l_index == -1)
        {
            ans += i;
        }
        else
        {
            ans += i - l_index;
        }
    }

    cout << ans;
}

int main()
{
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}