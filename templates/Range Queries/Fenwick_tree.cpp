#include <bits/stdc++.h>
using namespace std;

class FenwickTree{
public:
    vector<int> bit;
    int n;
    // Always remember BIT is 1-indexed

    FenwickTree(int n){
        this->n = n;
        bit = vector<int>(n+1, 0);
    }

    void update(int id, int val){
        while (id <= n){
            bit[id] += val;
            id += (id & -id);
        }
    }

    int query(int id){
        int ans = 0;
        while (id > 0){
            ans += bit[id];
            id -= (id & -id);
        }
        return ans;
    }
};

int main(){
    int n; cin>>n;
    FenwickTree ft(n);
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++){
        cin>>a[i];
        ft.update(i, a[i]);
    }

    int q;
    cin>>q;
    while (q--){
        int typeOfQuery;
        cin>>typeOfQuery;

        // Find the sum in the range L to R
        if (typeOfQuery == 1){
            int L, R; cin>>L>>R;
            cout<<ft.query(R) - ft.query(L-1)<<endl;
        }else{ // Replace the value at index id with val
            int id, val; cin>>id>>val;
            ft.update(id, -a[id]); // Firstly make it back to 0
            a[id] = val; // Update your original input array 'a'
            ft.update(id, a[id]); // Update the bit array
        }
    }
}