#include <iostream>
#include <vector>
using namespace std;

const int MAX = 17;

vector<vector<int>> table;

void build(vector<int>& p) {
    int n = p.size();
    table.resize(MAX, vector<int>(n));
    for(int i = 0; i < n; i++) {
        table[0][i] = p[i];
    }
    
    for(int i = 1; i < MAX; i++) {
        for(int j = 0; j < n; j++) {
            table[i][j] = table[i - 1][table[i - 1][j]];
        }
    }
}

int query(int a, int k) {
    for(int i = 0; i < MAX; i++) {
        int mask = (1 << i);
        if(k & mask) {
            a = table[i][a];
        }
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> parent(n);

    for(int i = 0; i < n; i++) {
        cin >> parent[i];
    }
    int q;
    cin >> q;

    build(parent);
    
    while(q-- > 0) {
        int a, k;
        cin >> a >> k;
        
        int ans = query(a, k);
        cout << ans << "\n";
    }

    return 0;
}
