#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Friend {
    int x, y, index;
};

double distance(const Friend& a, const Friend& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double stability(const Friend& a, const Friend& b, const Friend& c) {
    double d1 = distance(a, b);
    double d2 = distance(b, c);
    double d3 = distance(c, a);
    double max_dist = max({d1, d2, d3});
    double min_dist = min({d1, d2, d3});
    return max_dist - min_dist;
}

int main() {
    int N;
    cin >> N;
    
    vector<Friend> friends(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> friends[i].x >> friends[i].y;
        friends[i].index = i; // Store original index
    }

    // Sort friends based on coordinates
    sort(friends.begin(), friends.end(), [](const Friend& a, const Friend& b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });

    vector<vector<int>> groups;
    
    // Create groups of three
    for (int i = 0; i < N; i += 3) {
        groups.push_back({friends[i].index, friends[i + 1].index, friends[i + 2].index});
    }

    // Output the groups
    for (const auto& group : groups) {
        cout << group[0] << " " << group[1] << " " << group[2] << endl;
    }

    return 0;
}
