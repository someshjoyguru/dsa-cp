#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    int n, m, k, answer = 0;
    cin >> n >> m >> k;
    vector<int>a(n), b(m);

    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;

    auto update = [&](int index){
        for(int i = 0; i < b[index]; i++) a[i]++;
    };

    auto find = [&](vector<int>&a){
        int count = 0;
        for(int i = 0; i < n; i++) count += (a[i] == i + 1);
        return count;
    };

    for(int i = 0; i < min(2 * n, k); i++){
        int currEqual = find(a);
        // cout<<"currEqual : "<<currEqual<<endl;
        answer = max(answer, currEqual + (k - (i + 1)) / 2);
        // cout<<"answer : "<<answer<<endl;
        // for (auto j : a)cout<<j<<" ";
        // cout<<endl;
        update(i % m);
    }

    cout << answer << endl;

}

int main(){
    fastio()
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}