#include <iostream>
#include <string>

using namespace std;

int minimumFlips(string target) {
    int flips = 0;
    char current = '0'; 

    for (char c : target) {
        if (c != current) {
            flips++;
            current = (current == '0') ? '1' : '0';
        }
    }

    return flips;
}

int main() {
    string target="01011";
    // cout << "Enter the target binary string: ";
    // cin >> target;

    int result = minimumFlips(target);
    cout << "Minimum number of flips required: " << result << endl;

    return 0;
}
