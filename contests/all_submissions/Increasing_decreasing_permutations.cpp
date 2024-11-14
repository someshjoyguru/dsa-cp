#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Function to calculate the number of adjacent swaps needed to convert a permutation to the target permutation
int minimumSwaps(vector<int> &perm, const vector<int> &target) {
    vector<int> temp = perm;
    int swaps = 0;

    for (int i = 0; i < temp.size(); ++i) {
        while (temp[i] != target[i]) {
            swap(temp[i], temp[temp[i] - 1]);
            swaps++;
        }
    }
    return swaps;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> perm(N);
    iota(perm.begin(), perm.end(), 1);  // Fill perm with [1, 2, ..., N]

    // Define target increasing-decreasing order
    vector<int> target(N);
    int mid = (N + 1) / 2;
    for (int i = 0; i < mid; ++i)
        target[i] = i + 1;
    for (int i = mid; i < N; ++i)
        target[i] = N - (i - mid);

    ll totalSwaps = 0;
    do {
        // For each permutation, calculate the minimum swaps needed to reach the target
        totalSwaps = (totalSwaps + minimumSwaps(perm, target)) % M;
    } while (next_permutation(perm.begin(), perm.end()));

    cout << totalSwaps << endl;
    return 0;
}
