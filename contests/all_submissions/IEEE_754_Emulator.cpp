#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>

using namespace std;

// Function to convert hexadecimal string to float
float hexToFloat(const string& hex) {
    uint32_t intValue;
    stringstream ss;
    ss << hex << std::hex;
    ss >> intValue;

    float floatValue;
    memcpy(&floatValue, &intValue, sizeof(float));
    return floatValue;
}

// FMA function
float fmaOperation(float a, float b, float c) {
    return fma(a, b, c); // Using built-in fma for better precision
}

// NAND operation
uint32_t nandOperation(uint32_t a, uint32_t b) {
    return ~(a & b);
}

int main() {
    int T;
    cin >> T; // Number of test cases

    while (T--) {
        string C0;
        cin >> C0; // Initial hexadecimal value
        float C[100000]; // Stores floating-point values
        C[0] = hexToFloat(C0); // Convert C[0] to float

        int L;
        cin >> L; // Number of LUTs
        vector<vector<float>> LUT(L);

        for (int i = 0; i < L; ++i) {
            int k;
            cin >> k; // 2^ki size
            LUT[i].resize(1 << k); // Resize LUT
            for (int j = 0; j < (1 << k); ++j) {
                string lutHex;
                cin >> lutHex; // Hexadecimal for LUT
                LUT[i][j] = hexToFloat(lutHex); // Store float in LUT
            }
        }

        int Q;
        cin >> Q; // Number of commands
        vector<float> results(Q); // Store results of commands

        for (int n = 0; n < Q; ++n) {
            string command;
            cin >> command; // Read command
            if (command[0] == 'L') { // LUT command
                int i, j, b;
                sscanf(command.c_str(), "L%d %d %d", &i, &j, &b);
                uint32_t mask = (C[0] / (1 << j)) % (1 << b);
                results[n] = LUT[i][mask]; // LUT lookup
            } else if (command[0] == 'N') { // NAND command
                int i, j;
                sscanf(command.c_str(), "N%d %d", &i, &j);
                results[n] = nandOperation(*(uint32_t*)&C[i], *(uint32_t*)&C[j]); // Bitwise NAND
            } else if (command[0] == 'F') { // FMA command
                int i, j, k;
                sscanf(command.c_str(), "F%d %d %d", &i, &j, &k);
                results[n] = fmaOperation(C[i], C[j], C[k]); // FMA
            } else if (command[0] == 'C') { // Constant command
                string hexValue;
                sscanf(command.c_str(), "C%s", &hexValue);
                C[n] = hexToFloat(hexValue); // Store constant
            }
        }

        // Output the result of the last command in the test case
        cout << hex << std::setfill('0') << std::setw(8) << *(uint32_t*)&results[Q - 1] << endl;
    }

    return 0;
}
