#include <bits/stdc++.h>
using namespace std;
#define fastio()                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
#define ll long long

void dfs(int i, int j, vector<char> &path, vector<vector<char>> &mp, vector<string> &ans)
{
    if (mp[i][j] == 'B')
    {
        ans.push_back(string(path.begin(), path.end()));
        return;
    }
    int n = mp.size();
    int m = mp[0].size();
    if (i > 0 && mp[i - 1][j] != '#')
    {
        path.push_back('U');
        mp[i][j] = '#';
        dfs(i - 1, j, path, mp, ans);
        path.pop_back();
        mp[i][j] = '.';
    }
    if (j > 0 && mp[i][j - 1] != '#')
    {
        path.push_back('L');
        mp[i][j] = '#';
        dfs(i, j - 1, path, mp, ans);
        path.pop_back();
        mp[i][j] = '.';
    }
    if (i < n - 1 && mp[i + 1][j] != '#')
    {
        path.push_back('D');
        mp[i][j] = '#';
        dfs(i + 1, j, path, mp, ans);
        path.pop_back();
        mp[i][j] = '.';
    }
    if (j < m - 1 && mp[i][j + 1] != '#')
    {
        path.push_back('R');
        mp[i][j] = '#';
        dfs(i, j + 1, path, mp, ans);
        path.pop_back();
        mp[i][j] = '.';
    }
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> mp(n, vector<char>(m));
    ll startx, starty;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            mp[i][j] = s[j];
            if (s[j] == 'A')
            {
                startx = i;
                starty = j;
            }
        }
    }
    vector<char> path;
    vector<string> ans;
    dfs(startx, starty, path, mp, ans);
    if (ans.size() == 0)
        cout << "NO";
    else
    {
        cout << "YES" << endl;
        string st = ans[0];
        for (int i = 0; i < ans.size(); i++)
        {
            if (st.size() > ans[i].size())
            {
                st = ans[i];
            }
        }
        cout << st.size() << endl;
        cout << st;
    }
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