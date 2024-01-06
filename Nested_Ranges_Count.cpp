#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;

struct range{
    int l, r, index;
    bool operator < (const range &other) const{
        if(l == other.l)
            return r > other.r;
        return l < other.l;
    }
};

void solve(){
    ll n;
    cin >> n;
    vector<range> ranges(n);
    vector<int> contained(n);
    vector<int> contains(n);
    ordered_set<pair<int, int>> rightBoundaries;

    for(int i = 0; i < n; i++){
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].index = i;
    }
    sort(ranges.begin(), ranges.end());

    for(int i = 0; i < n; i++){
        rightBoundaries.insert({ranges[i].r, -1 * i});
        contained[ranges[i].index] = rightBoundaries.size() - rightBoundaries.order_of_key({ranges[i].r, -1 * i}) - 1;
    }

    rightBoundaries.clear();
    for(int i = n - 1; i >= 0; i--){
        contains[ranges[i].index] = rightBoundaries.order_of_key({ranges[i].r, -1 * i});
        rightBoundaries.insert({ranges[i].r, -1 * i});
    }

    //contains
    for (int i = 0; i < n; i++)
        cout << contains[i] << " ";
    cout << endl;
    //contained
    for (int i = 0; i < n; i++)
        cout << contained[i] << " ";
}

int main(){
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
