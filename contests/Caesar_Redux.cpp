#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll s;
    string t;
    cin >> s;
    cin.ignore();
    getline(cin, t);

    istringstream iss(t);
    vector<string> words;
    string word;

    while (iss >> word)
    {
        words.push_back(word);
    }
    bool isplain = false;
    for (const auto &w : words)
    {
        if (w == "the")
        {
            isplain = true;
            break;
        }
    }
    // cout<<isplain<<endl;
    if (isplain)
    {
        for (const auto &w : words)
        {
            for (auto c : w)
            {
                cout << char((c - 'a' - s + 26) % 26 + 'a');
            }
            cout << " ";
        }
        cout << endl;
    }
    else
    {
        for (const auto &w : words)
        {
            for (auto c : w)
            {
                cout << char((c - 'a' + s + 26) % 26 + 'a');
            }
            cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    ll t = 1;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        solve();
    }
    return 0;
}