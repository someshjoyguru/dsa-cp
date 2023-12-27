#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    cin.ignore(); 
    vector<vector<string>> v;
    for (ll i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        vector<string> words;
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        v.push_back(words);
    }
    for (int i=0; i<v.size(); i++){
        map<char, int> mp;
        for (int j=0; j<v[i].size(); j++){
            for (int k=0; k<v[i][j].size(); k++){
                if (v[i][j][k] == 'a' || v[i][j][k] == 'b' || v[i][j][k] == 'c' || v[i][j][k] == 'd' || v[i][j][k] == 'e'|| v[i][j][k] == 'f'|| v[i][j][k] == 'g'){
                    if (mp.find(v[i][j][k]) == mp.end()){
                        mp[v[i][j][k]] = 1;
                    }
                    else{
                        mp[v[i][j][k]]++;
                    }
                }
            }
        }
        char k;
        int mmm = INT_MIN; 

        for (const auto &pair : mp) {
            if (pair.second > mmm) {
                mmm = pair.second;
                k = pair.first;
            }
        }
        cout<<char(k-32)<<endl;
    }
}

int main(){
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}