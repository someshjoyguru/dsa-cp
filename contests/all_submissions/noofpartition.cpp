#include <bits/stdc++.h>
using namespace std;

// Helper function to calculate the differences between consecutive characters in a string
vector<int> get_differences(const string& s) {
    vector<int> diffs;
    for (size_t i = 0; i < s.size() - 1; ++i) {
        diffs.push_back(s[i + 1] - s[i]);
    }
    return diffs;
}

string findOdd(vector<string> series) {
    map<vector<int>, vector<int>> mp;
    int i = 0;

    for (const auto& s : series) {
        vector<int> diffs = get_differences(s);
        mp[diffs].push_back(i);
        i++;
    }
    for (const auto& pair : mp) {
        cout<<pair.first[0]<<" "<<pair.first[1]<<" "<<pair.second.size()<<endl;
        if (pair.second.size() == 1) {
            return series[pair.second[0]];
        }
    }

    return ""; 
}

int main() {
    vector<string> series = {"ACB", "BDC", "CED", "DEF"};
    string odd_string = findOdd(series);
    cout << "The odd string is: " << odd_string << endl;
    return 0;
}
