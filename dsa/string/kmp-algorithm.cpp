#include <bits/stdc++.h>
using namespace std;

class SubstringSearch {
public:
    // slow method of pattern matching (Brute Force) O(mn)
    bool hasSubstring(const char* text, const char* pattern) {
        int i = 0;
        int j = 0;
        int k = 0;
        while (text[i] != '\0' && pattern[j] != '\0') {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            } else {
                j = 0;
                k++;
                i = k;
            }
        }
        return (pattern[j] == '\0');
    }


    // kmp algorithm 
    vector<int> computeTemporaryArray(const char* pattern) {
        int len = strlen(pattern);
        vector<int> lps(len, 0);
        int index = 0;
        for (int i = 1; i < len;) {
            if (pattern[i] == pattern[index]) {
                lps[i] = index + 1;
                index++;
                i++;
            } else {
                if (index != 0) {
                    index = lps[index - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    bool KMP(const char* text, const char* pattern) {
        vector<int> lps = computeTemporaryArray(pattern);
        int i = 0;
        int j = 0;
        while (text[i] != '\0' && pattern[j] != '\0') {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return (pattern[j] == '\0');
    }
};

int main() {
    const char* str = "abcxabcdabcdabcy";
    const char* subString = "abcdabcy";
    SubstringSearch ss;
    bool result = ss.KMP(str, subString);
    cout << boolalpha << result;
    return 0;
}
