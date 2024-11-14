#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    fast;
    int N, x;
    cin >> N >> x;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    
    sort(A.begin(), A.end());
    
    vector<stack<int>> stacks;
    
    for (int length : A) {
        bool placed = false;
        for (auto& st : stacks) {
            if (st.top() + x <= length) {
                st.push(length);
                placed = true;
                break;
            }
        }
        if (!placed) {
            stack<int> new_stack;
            new_stack.push(length);
            stacks.push_back(move(new_stack));
        }
    }
    
    cout << stacks.size() << '\n';
    for (auto& st : stacks) {
        vector<int> stack_elements;
        while (!st.empty()) {
            stack_elements.push_back(st.top());
            st.pop();
        }
        cout << stack_elements.size();
        for (auto it = stack_elements.rbegin(); it != stack_elements.rend(); ++it) {
            cout << " " << *it;
        }
        cout << '\n';
    }

    return 0;
}
