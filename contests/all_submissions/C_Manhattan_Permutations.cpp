#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a;
    cin >> a;
    for (int x = 0; x < a; ++x) {
        int n, k;
        cin >> n >> k;
        if (k % 2 == 1) {
            cout << "No" << endl;
            continue;
        }
        vector<int> c(n);
        for (int i=0; i<n; i++){
            c[i]=i+1;
        }
        int d = n - 1;
        for (int i = 0; i < n; ++i) {
            while ((d > 0) && (i < d) && k < (abs(c[i] - (d + 1)) + abs(c[d] - (i + 1)))) {
                --d;
            }
            if (k == 0 || i >= d) {
                break;
            }
            k -= abs(c[i] - (d + 1)) + abs(c[d] - (i + 1));
            swap(c[i], c[d]);
            --d;
            if (k == 0 || i >= d) {
                break;
            }
        }
        if (k == 0) {
            cout << "Yes" << endl;
            for (int j = 0; j < n; ++j) {
                cout << c[j] << " ";
            }
            cout << endl;
        } else {
            cout << "No" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
