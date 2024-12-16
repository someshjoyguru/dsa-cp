#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cerr.rdbuf(cout.rdbuf());
#define f(i,a,b) for (ll (i)=(a); (i)<(b); (i)++)
#define rf(i,a,b) for (ll (i)=(a); (i)>=(b); (i)--)
#define vll vector<ll>
#define vvll vector<vll>
#define in(n) ll n; cin>>n;
#define sin(s) string (s); cin>>(s);
#define vin(v,n) vll (v)(n); f(i,0,n)cin>>(v)[i];
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sort(v) sort(all(v));
#define rsort(v) sort(v) reverse(all(v));
#define pYES cout<<"YES\n";
#define pNO cout<<"NO\n";
const ll mod = 1000000007;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

template <typename T>
void _print(T x) { cerr << x; }
template <typename T, typename V>
void _print(pair<T, V> p) { cerr << "{"; _print(p.first); cerr << ", "; _print(p.second); cerr << "}"; }
template <typename T>
void _print(vector<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <typename T>
void _print(set<T> s) { cerr << "{ "; for (T i : s) { _print(i); cerr << " "; } cerr << "}"; }
template <typename T, typename V>
void _print(map<T, V> m) { cerr << "{ "; for (auto i : m) { _print(i); cerr << " "; } cerr << "}"; }
/* *********************Template ends here************** */


void solve() {
    in(n) in(k)
    vin(v,n)
    f(i,0,n){
        ll tmp=v[i];
        f(j,i,n){
            tmp=(tmp&v[j]);
            if (tmp==k){
                pYES
                cout<<j-i+1<<endl;
                f(c,i,j+1){
                    cout<<v[c]<<" ";
                }
                cout<<endl;
                return;
            }
        }
    }
    pNO
    return;
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Function to generate all subsets' AND values and their indices
void generateSubsets(const vector<int>& arr, map<int, vector<vector<int>>>& subsets) {
    int n = arr.size();
    int subsetCount = 1 << n; // 2^n subsets

    for (int mask = 1; mask < subsetCount; ++mask) {
        int currentAnd = -1;
        vector<int> indices;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                if (currentAnd == -1) {
                    currentAnd = arr[i];
                } else {
                    currentAnd &= arr[i];
                }
                indices.push_back(i); // 0-based index
            }
        }
        subsets[currentAnd].push_back(indices);
    }
}

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        // Split array into two halves
        int mid = N / 2;
        vector<int> left(A.begin(), A.begin() + mid);
        vector<int> right(A.begin() + mid, A.end());

        // Generate subsets for both halves
        map<int, vector<vector<int>>> leftSubsets, rightSubsets;
        generateSubsets(left, leftSubsets);
        generateSubsets(right, rightSubsets);

        bool found = false;
        vector<int> result;

        // Check if we can combine subsets from left and right to get K
        for (const auto& [leftAnd, leftIndicesList] : leftSubsets) {
            int neededRightAnd = K & leftAnd; // To satisfy AND = K

            if (rightSubsets.count(neededRightAnd)) {
                for (const auto& leftIndices : leftIndicesList) {
                    for (const auto& rightIndices : rightSubsets[neededRightAnd]) {
                        // Combine indices from both halves
                        for (int idx : leftIndices) {
                            result.push_back(idx + 1); // Convert to 1-based
                        }
                        for (int idx : rightIndices) {
                            result.push_back(mid + idx + 1); // Convert to 1-based
                        }
                        found = true;
                        break;
                    }
                    if (found) break;
                }
                if (found) break;
            }
        }

        // Output the result
        if (found) {
            cout << "YES\n";
            cout << result.size() << "\n";
            for (int idx : result) {
                cout << idx << " ";
            }
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
