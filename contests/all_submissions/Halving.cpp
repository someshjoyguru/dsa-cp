#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define ll long long

ll n;
vector<ll> C, R, B;

ll func(vector<ll>& C, vector<ll>& R, vector<ll>& B) {
    set<ll> known_values;
    vector<ll> missing_positions;

    // Identify known and missing values in C
    for (ll i = 0; i < 2 * n; i++) {
        if (C[i] != -1) {
            known_values.insert(C[i]);
        } else {
            missing_positions.push_back(i);
        }
    }

    // Generate all possible values that could be missing
    vector<ll> missing_values;
    for (ll i = 1; i <= 2 * n; i++) {
        if (known_values.find(i) == known_values.end()) {
            missing_values.push_back(i);
        }
    }

    ll missing_count = missing_values.size();
    ll valid_count = 1;

    // Calculate valid configurations for each pair based on R and B
    for (ll i = 0; i < n; i++) {
        ll idx1 = 2 * i, idx2 = 2 * i + 1;
        if (C[idx1] == -1 && C[idx2] == -1) {
            // Both values are missing
            valid_count = (valid_count * 2) % MOD;
        } else if (C[idx1] != -1 && C[idx2] != -1) {
            // Both values are known, ensure they satisfy the condition
            if ((R[i] == 0 && min(C[idx1], C[idx2]) != B[i]) || 
                (R[i] == 1 && max(C[idx1], C[idx2]) != B[i])) {
                return 0;
            }
        } else {
            // One value is missing, check possible assignment
            ll known_value = (C[idx1] == -1) ? C[idx2] : C[idx1];
            if ((R[i] == 0 && known_value > B[i]) || 
                (R[i] == 1 && known_value < B[i])) {
                return 0;
            }
        }
    }

    // Factorial of remaining missing values to account for distinct permutations
    for (ll i = 1; i <= missing_count; i++) {
        valid_count = (valid_count * i) % MOD;
    }

    return valid_count;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    C.resize(2 * n);
    R.resize(n);
    B.resize(n);

    for (ll i = 0; i < 2 * n; i++) cin >> C[i];
    for (ll i = 0; i < n; i++) cin >> R[i];
    for (ll i = 0; i < n; i++) cin >> B[i];

    cout << func(C, R, B) << endl;
    return 0;
}
