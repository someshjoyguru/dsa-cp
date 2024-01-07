#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    std::vector<int> arr = {5, 2, 8, 6, 3, 6, 9, 7};
    auto result = longestDecreasingSubsequence(arr);
    
    std::cout << "Longest Decreasing Subsequence: ";
    for (int num : result.first) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Other elements in the same order: ";
    for (int num : result.second) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
