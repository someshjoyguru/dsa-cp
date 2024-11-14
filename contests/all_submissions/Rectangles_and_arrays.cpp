#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(i,a,b) for (ll (i)=(a); (i)<(b); (i)++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define sin(s) string (s); cin>>(s);
#define vin(v,n) vll (v)(n); f(i,0,n)cin>>(v)[i];
#define all(v) (v).begin(),(v).end()
#define sort(v) sort(all(v));
#define pYES cout<<'YES'<<endl;
#define pNO cout<<'NO'<<endl;

long long calculateMaxRectangleArea(const vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n), right(n);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        left[i] = st.empty() ? 0 : st.top() + 1;
        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        right[i] = st.empty() ? n - 1 : st.top() - 1;
        st.push(i);
    }

    long long maxArea = 0;
    for (int i = 0; i < n; ++i) {
        long long width = right[i] - left[i] + 1;
        long long area = width * heights[i];
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

long long maxRectangleAreaWithOneModification(vector<int> heights, int X) {
    long long maxArea = calculateMaxRectangleArea(heights);

    for (int i = 0; i < heights.size(); ++i) {
        int original = heights[i];
        heights[i] = X;
        maxArea = max(maxArea, calculateMaxRectangleArea(heights));
        heights[i] = original;
    }

    return maxArea;
}

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> heights(N);
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    cout << maxRectangleAreaWithOneModification(heights, X) << endl;
    return 0;
}
