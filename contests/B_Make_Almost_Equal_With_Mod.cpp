#include <bits/stdc++.h>
using namespace std;
#define ll long long

// ll func(ll mid, vector<ll>& v){
//     ll n=v.size();
//     map<ll,ll> mp;
//     for (ll i=0; i<n; i++){
//         mp[v[i]%mid]++;
//         if (mp.size()>2) return 1;
//     }
//     if (mp.size()==2) return 0;
//     return -1;
// }
// void solve(){
//     ll n,maxi=0;
//     cin>>n;
//     vector<ll> v(n);
//     for (ll i=0; i<n; i++){
//         cin>>v[i];
//         maxi=max(maxi,v[i]);
//     }
//     ll low=1, high=maxi,mid=0;
//     while (low<=high){
//         mid=low+(high-low)/2;
//         ll k = func(mid, v);
//         if (k==0){
//             cout<<mid<<endl;
//             return;
//         }else if(k==1){
//             high=mid-1;
//         }else{
//             low=mid+1;
//         }
//     }
//     return;
// }

int powerOfTwo(int n)
{
    if(n==0) { return 0; }
    while(n != 1)
    {
        n = n/2;
        if(n%2 != 0 && n != 1){ return 0; }
    }
    return 1;
}

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for (ll i=0; i<n; i++)cin>>v[i];
    bool allEven=true,allOdd=true;
    for (ll i=0; i<n; i++)if(v[i]%2)allEven=false;
    for (ll i=0; i<n; i++)if(v[i]%2==0)allOdd=false;
    if (allEven || allOdd){
        cout<<4<<endl;
        return;
    }
    cout<<2<<endl;
    return;
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}