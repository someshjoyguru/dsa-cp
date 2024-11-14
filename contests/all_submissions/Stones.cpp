#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double dp[41][41][41][41][2];  // DP array to store probabilities
bool computed[41][41][41][41][2];  // Memoization array

// Recursive function to calculate probability of Alice winning
double probability(int R1, int B1, int R2, int B2, int turn) {
    // Base cases
    if (R1 == 0 || B1 == 0) return 0.0;  // Alice loses
    if (R2 == 0 || B2 == 0) return 1.0;  // Alice wins
    
    if (computed[R1][B1][R2][B2][turn])  // If already computed, return stored result
        return dp[R1][B1][R2][B2][turn];

    double result = 0.0;

    if (turn == 0) {  // Alice's turn
        // Alice picks red
        result += 0.5 * ((B2 > 0 ? probability(R1 - 1, B1, R2, B2, 1) : 0) +
                         (R2 > 0 ? probability(R1, B1, R2 - 1, B2, 1) : 0));
        
        // Alice picks blue
        result += 0.5 * ((B2 > 0 ? probability(R1, B1 - 1, R2, B2, 1) : 0) +
                         (R2 > 0 ? probability(R1, B1, R2, B2 - 1, 1) : 0));
        
    } else {  // Bob's turn
        // Bob picks red
        result += 0.5 * ((B1 > 0 ? probability(R1, B1, R2 - 1, B2, 0) : 0) +
                         (R1 > 0 ? probability(R1 - 1, B1, R2, B2, 0) : 0));

        // Bob picks blue
        result += 0.5 * ((B1 > 0 ? probability(R1, B1, R2, B2 - 1, 0) : 0) +
                         (R1 > 0 ? probability(R1, B1 - 1, R2, B2, 0) : 0));
    }

    computed[R1][B1][R2][B2][turn] = true;  // Mark as computed
    return dp[R1][B1][R2][B2][turn] = result;  // Store and return result
}

int main() {
    int R1, B1, R2, B2;
    cin >> R1 >> B1 >> R2 >> B2;

    // Print the probability of Alice winning with 10^-6 precision
    cout << fixed << setprecision(9) << probability(R1, B1, R2, B2, 0) << endl;

    return 0;
}
