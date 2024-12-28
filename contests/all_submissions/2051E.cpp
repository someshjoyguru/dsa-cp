#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll solve_test_case() {
    int n, k;
    cin >> n >> k;
    
    vector<pair<ll, ll>> customers(n);
    for (int i = 0; i < n; i++) cin >> customers[i].first;  // a values
    for (int i = 0; i < n; i++) cin >> customers[i].second; // b values
    
    // Sort by 'a' values to process customers in order
    sort(customers.begin(), customers.end());
    
    ll max_revenue = 0;
    vector<ll> price_points;
    
    // Add all price points to vector
    for (const auto& c : customers) {
        price_points.push_back(c.first);
        price_points.push_back(c.second);
    }
    sort(price_points.begin(), price_points.end());
    price_points.erase(unique(price_points.begin(), price_points.end()), price_points.end());
    
    // For each price point
    for (ll price : price_points) {
        ll positive = 0, negative = 0;
        
        // Count reviews using binary search
        auto pos = upper_bound(customers.begin(), customers.end(), 
                             make_pair(price, (ll)2e9));
        positive = pos - customers.begin();
        
        // Count negative reviews
        for (const auto& c : customers) {
            if (c.first > price && c.second >= price) {
                negative++;
            }
        }
        
        // If negative reviews within limit, update revenue
        if (negative <= k) {
            ll total_customers = positive + negative;
            max_revenue = max(max_revenue, price * total_customers);
        }
    }
    
    return max_revenue;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        cout << solve_test_case() << endl;
    }
    
    return 0;
}