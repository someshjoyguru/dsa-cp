#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, m;
    cin >> n >> m;
    cin.ignore(); // Ignore the newline character after reading n and m
    
    vector<vector<string>> v1, v2;
    
    // Read n lines and split into vectors
    for (ll i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        vector<string> words;
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        v1.push_back(words);
    }

    cin.ignore();
    
    // Read m lines and split into vectors
    for (ll i = 0; i < m; ++i) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        vector<string> words;
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        v2.push_back(words);
        cin.ignore();
    }
    
    vector<ll> ans;
    for ( auto v2v2: v2){
        string v2l=v2v2[v2v2.size()-1];
        transform(v2l.begin(), v2l.end(), v2l.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
        bool found=false;
        for (int i = 0; i < v1.size(); ++i) {
            for (int j = 0; j < v1[i].size(); ++j) {
                if (v1[i][j] == v2l) {
                    transform(v1[i][j].begin(), v1[i][j].end(), v1[i][j].begin(), [](unsigned char c) {
                        return std::tolower(c);
                    });
                    ans.push_back(i);
                    found = true;
                    break;
                }
            }
            if (found){
                break;
            }
        }
        if (!found){
            ans.push_back(-1);
        }
    }

    // for (auto a: ans){
    //     cout<<a<<" ";
    // }

    map<ll, pair<char,ll>> mp;
    ll k=0;
    for (ll i=0; i<ans.size(); ++i){
        if (ans[i]==-1){
            mp[-1].first='X';
        }
        if (mp.find(ans[i])==mp.end()){
            mp[ans[i]].first='A'+k;
            mp[ans[i]].second=1;
            k++;
        }else{
            mp[ans[i]].second++;
        }
    }

    ll x=0;
    for (auto a: ans){
        if (a==-1){
            cout<<'X';
            continue;
        }
        if (mp[a].second<2){
            cout<<'X';
            x++;
        }
        else cout<<char(mp[a].first-x);
    }
    // // Output v1
    // cout << "v1={{";
    // for (ll i = 0; i < v1.size(); ++i) {
    //     cout << "{";
    //     for (ll j = 0; j < v1[i].size(); ++j) {
    //         cout << v1[i][j];
    //         if (j < v1[i].size() - 1) {
    //             cout << ",";
    //         }
    //     }
    //     cout << "}";
    //     if (i < v1.size() - 1) {
    //         cout << ",";
    //     }
    // }
    // cout << "}}" << endl;
    
    // // Output v2
    // cout << "v2={{";
    // for (ll i = 0; i < v2.size(); ++i) {
    //     cout << "{";
    //     for (ll j = 0; j < v2[i].size(); ++j) {
    //         cout << v2[i][j];
    //         if (j < v2[i].size() - 1) {
    //             cout << ",";
    //         }
    //     }
    //     cout << "}";
    //     if (i < v2.size() - 1) {
    //         cout << ",";
    //     }
    // }
    // cout << "}}" << endl;

}

int main()
{
    ll t = 1;
    // cin >> t;
    // cin.ignore();
    while (t--)
    {
        solve();
    }
    return 0;
}