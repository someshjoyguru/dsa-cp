#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void f(vector<ll>& arr, vector<ll>& sums) {
    int n = arr.size();
    int total = 1 << n;
    
    for (int i = 0; i < total; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                sum += arr[j];
            }
        }
        sums.push_back(sum);
    }
}

void solve(){
    ll n,x,z;
    cin>>n>>x>>z;
    vector<ll> v(n);
    for (int i=0; i<n; i++)cin>>v[i];
    vector<ll> sums;
    f(v,sums);
    sort(sums.begin(),sums.end());
    for (int i=0; i<sums.size(); i++){
        // if ((sums[i]+z)%x==0){
        //     cout<<(sums[i]+z)/x<<endl;
        //     return;
        // }
        cout<<sums[i]<<" ";
    }
    cout<<endl;
    // cout<<-1<<endl;
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