#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    if (n<0 || n==2){
        cout<<-1<<endl;
        return;
    }
    if (n==1){
        cout<<1<<endl;
        return;
    }
    vector<vector<int>> vv = {{1, 2, 3}, {6, 4, 5}, {8, 9, 7}};
    if (n==3){
        for (auto v: vv){
            for (auto i: v){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        return;
    }
    vector<vector<int>> vvv(n, vector<int>(n));
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            vvv[i][j] = vv[i][j];
        }
    }
    for (int i=4; i<=n; i++){
        int x= (i-1)*(i-1)+1;
        for (int j=0; j<i; j++){
            vvv[i-1][j].push_back(x++);
        }
    }
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}