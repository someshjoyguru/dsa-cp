#include <bits/stdc++.h>
using namespace std;

bool is(const string &a, const string &b) {
    return b.find(a) != string::npos;
}

int main() {
    int n;
    cin >> n;
    vector<string> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<string>> x;
    x.push_back({v[0]});
    for (int i=1; i<n; i++){
        sort(x.begin(), x.end(), [](vector<string> &a, vector<string> &b) {
            return a.size() > b.size();
        });
        bool dd=false;
        for (int j=0; j<x.size(); j++){
            bool fl=true;
            for (auto xx: x[j]){
                if (is(v[i], xx) || is(xx, v[i])){
                    fl=false;
                    break;
                }
            }
            if (fl) {
                x[j].push_back(v[i]);
                dd=true;
                break;
            }
        }
        if (!dd){
            x.push_back({v[i]});
        }
    }
    int cnt = 0;
    for (int i = 0; i < x.size(); i++) {
        cnt=max(cnt, (int)x[i].size());
    }

    cout << cnt << endl;
    return 0;
}
