#include <bits/stdc++.h>
using namespace std;

struct Query {
    int L, R, index;
};

bool compare(Query a, Query b) {
    int block_size = sqrt(a.R - a.L + 1);
    if (a.L / block_size != b.L / block_size)
        return a.L / block_size < b.L / block_size;
    return a.R < b.R;
}

void add(int pos, const vector<int>& array, unordered_map<int, int>& freqMap, int& validCount, int k) {
    freqMap[array[pos]]++;
    if (freqMap[array[pos]] == k)
        validCount++;
    else if (freqMap[array[pos]] == k + 1)
        validCount--;
}

void remove(int pos, const vector<int>& array, unordered_map<int, int>& freqMap, int& validCount, int k) {
    if (freqMap[array[pos]] == k)
        validCount--;
    else if (freqMap[array[pos]] == k + 1)
        validCount++;
    freqMap[array[pos]]--;
}

int get_answer(int N, int K, vector<int>& A, int Q, int two, vector<vector<int>>& queries) {
    vector<Query> sortedQueries(Q);
    for (int i = 0; i < Q; ++i) {
        sortedQueries[i] = {queries[i][0], queries[i][1], i};
    }

    sort(sortedQueries.begin(), sortedQueries.end(), compare);

    unordered_map<int, int> freqMap;
    int currentL = 0, currentR = -1;
    int validCount = 0;
    int resultIndicesSum = 0;

    for (int i = 0; i < Q; ++i) {
        int L = sortedQueries[i].L;
        int R = sortedQueries[i].R;

        while (currentR < R) add(++currentR, A, freqMap, validCount, K);
        while (currentR > R) remove(currentR--, A, freqMap, validCount, K);
        while (currentL < L) remove(currentL++, A, freqMap, validCount, K);
        while (currentL > L) add(--currentL, A, freqMap, validCount, K);

        bool allEqualK = (validCount == freqMap.size());

        if (allEqualK) {
            resultIndicesSum += sortedQueries[i].index;
        }
    }

    return resultIndicesSum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int K;
    cin >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int Q;
    cin >> Q;

    vector<vector<int>> queries(Q, vector<int>(2));
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i][0] >> queries[i][1];
    }

    int result = get_answer(N, K, A, Q, 2, queries);
    cout << "Sum of query indices where all elements have frequency " << K << " is: " << result << endl;

    return 0;
}
