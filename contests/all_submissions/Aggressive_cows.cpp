#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPos(int mid, int c, vector<ll>& loc){
    int ccnt=1,last=0;
    for (int i=1; i<loc.size(); i++){
        if (loc[i]-loc[last]>=mid){
            ccnt++;
            last=i;
        }
        if (ccnt>=c){
            return true;
        }
    }
    return false;
}
void solve(){
    ll n,c;
    cin>>n>>c;
    vector<ll> loc(n);
    for (int i=0; i<n; i++)cin>>loc[i];
    sort(loc.begin(),loc.end());
    ll low = 1, high = 1e9;
    ll mid;
    while (low<=high){
        mid = low +(high-low)/2;
        if (isPos(mid, c, loc)==true){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    cout<<high<<endl;
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}