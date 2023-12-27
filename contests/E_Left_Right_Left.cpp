#include <bits/stdc++.h>
using namespace std;
#define ll long long

int ls(vector<int>& nums, int target) {
    unordered_map<int, int> ps;
    int sum = 0;
    int ml = 0;

    ps[0] = -1;

    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        
        if (ps.find(sum - target) != ps.end()) {
            ml = max(ml, i - ps[sum - target]);
        }

        if (ps.find(sum) == ps.end()) {
            ps[sum] = i;
        }
    }

    return ml;
}

void solve(){
    ll n,s;
    cin>>n>>s;
    vector<int> v(n,0);
    for (int i=0; i<n; i++){
        cin>>v[i];
    }
    if (ls(v,s)==0){
        cout<<-1<<endl;
    }else{
        cout<<n-ls(v,s)<<endl;
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