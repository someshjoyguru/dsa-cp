#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the maximum subarray sum using Kadane's Algorithm
int maxSubArraySum(const vector<int>& arr) {
    int max_sum = arr[0];
    int current_sum = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        current_sum = max(arr[i], current_sum + arr[i]);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<int> A(N);
        int base_sum = 0;
        
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            base_sum += A[i];
        }
        
        // Maximum subarray sum without any flips
        int max_sum_no_flip = maxSubArraySum(A);
        
        // Try flipping each consecutive pair and calculate the potential maximum sum
        int max_sum_with_flip = max_sum_no_flip;
        
        for (int i = 0; i < N; i += 2) {
            // Flip the pair A[i] and A[i+1]
            int new_val_1 = -A[i];
            int new_val_2 = -A[i + 1];
            
            // Calculate modified array with this flipped pair
            int original_sum = A[i] + A[i + 1];
            int flipped_sum = new_val_1 + new_val_2;
            int gain = flipped_sum - original_sum;
            
            // Update the base sum temporarily for max subarray calculation
            int possible_max_sum = base_sum + gain;
            max_sum_with_flip = max(max_sum_with_flip, possible_max_sum);
        }
        
        // Output the maximum of all cases
        cout << max(max_sum_no_flip, max_sum_with_flip) << "\n";
    }
    
    return 0;
}
