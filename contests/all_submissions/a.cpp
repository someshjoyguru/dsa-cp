#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(i,power,b) for (ll (i)=(power); (i)<(b); (i)++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define sin(s) string (s); cin>>(s);
#define vin(vec,n) vll (vec)(n); f(i,0,n)cin>>(vec)[i];
#define all(vec) (vec).begin(),(vec).end()
#define sort(vec) sort(all(vec));
#define pYES cout<<"YES"<<endl;
#define pNO cout<<"NO"<<endl;

class Solution {
public:
static bool peak(const vector<int>& nums, int i) {
    if (i <= 0 || i >= nums.size() - 1) return false;
    return nums[i] > nums[i-1] && nums[i] > nums[i+1];
}

class SegmentTree {
private:
    vector<int> tree;
    int n;

    void build(const vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = peak(nums, start) ? 1 : 0;
        } else {
            int mid = (start + end) / 2;
            build(nums, 2 * node + 1, start, mid);
            build(nums, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void update(const vector<int>& nums, int node, int start, int end, int idx) {
        if (start == end) {
            tree[node] = peak(nums, idx) ? 1 : 0;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(nums, 2 * node + 1, start, mid, idx);
            } else {
                update(nums, 2 * node + 2, mid + 1, end, idx);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start &&  end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int lq = query(2 * node + 1, start, mid, l, r);
        int rq = query(2 * node + 2, mid + 1, end, l, r);
        return lq + rq;
    }

public:
    SegmentTree(const vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        build(nums, 0, 0, n - 1);
    }

    void update(const vector<int>& nums, int idx) {
        update(nums, 0, 0, n - 1, idx);
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    vector<int> ans;
    SegmentTree tre(nums);

    for (const auto& query : queries) {
        if (query[0] == 1) {
            int l = query[1];
            int r = query[2];
            ans.push_back(tre.query(l + 1, r - 1));
        } else if (query[0] == 2) {
            int index = query[1];
            int val = query[2];
            nums[index] = val;
            if (index > 0) tre.update(nums, index - 1);
            tre.update(nums, index);
            if (index < n - 1) tre.update(nums, index + 1);
        }
    }

    return ans;
}
};