#include <iostream>
using namespace std;

// Function to compute XOR from 1 to n
// long long xorUpto(long long n) {
//     if (n % 4 == 0) return n;
//     if (n % 4 == 1) return 1;
//     if (n % 4 == 2) return n + 1;
//     return 0;
// }

// // Function to compute XOR from a to b
// long long xorRange(long long a, long long b) {
//     return xorUpto(b) ^ xorUpto(a - 1);
// }

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long l, r;
        int i, k;
        cin >> l >> r >> i >> k;
        
        // Calculate the modulus value 2^i
        long long modVal = 1LL << i;
        
        // Calculate starting point for interesting numbers not congruent to k mod 2^i
        long long resultXOR = 0;
        
        // We iterate through blocks of size 2^i from l to r and calculate XOR for interesting numbers
        for (long long start = (l / modVal) * modVal; start <= r; start += modVal) {
            for (long long j = 0; j < modVal; ++j) {
                long long x = start + j;
                if (x >= l && x <= r && x % modVal != k) {
                    resultXOR ^= x;
                }
            }
        }
        
        cout << resultXOR << endl;
    }
    return 0;
}
