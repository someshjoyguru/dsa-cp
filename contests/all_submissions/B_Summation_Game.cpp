#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll n,k,x;
    cin>>n>>k>>x;
    vector<ll> v(n);
    ll neg=0, pos=0;
    for (ll i=0; i<n; i++){
        cin>>v[i];
        if (v[i]<0)neg++;
        if (v[i]>0)pos++;
    }
    sort(v.begin(),v.end());
    for (ll i=0; i<n; i++)cout<<v[i]<<" ";
    cout<<endl;
    
    vector<ll> presum(n,0);
    ll sum=0;
    for (ll i=0; i<n; i++){
        sum+=v[i];
        presum[i]=sum;
    }

    for (ll i=0; i<n; i++)cout<<presum[i]<<" ";
    cout<<endl;
    ll right = n-1;
    ll left=right-x+1;
    ll ans;
    if (left<=0){
        ans=-1*presum[right];
    }else{
        ans=2*presum[left-1]-presum[right];
    }
    ll i=max(n-k,0ll);
    for (;i<n;i++){
        if (!i){
            ans=max(ans,0ll);
            continue;
        }
        right=i-1;
        left=right-x+1;
        if (left<=0)ans=max(ans,-1*presum[right]);
        else ans=max(ans,2*presum[left-1]-presum[right]);
    }
    cout<<ans<<endl;
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

// ll sum = accumulate
// if (n==1 && pos==1){
//     cout<<0<<endl;
//     return;
// }
// ll sum=0;
// if (neg==0){
//     sum=accumulate(v.begin(),v.end(),0);
// }
// else if (k>=neg){
//     sum=accumulate(v.begin()+neg,v.end(),0);
// }else{
//     sum=accumulate(v.begin()+k,v.end(),0);
// }

// if (pos==0){
// }
// else if (x>=pos){
//     sum-=2*accumulate(v.rbegin(),v.rbegin()+pos,0);
// }else{
//     sum-=2*accumulate(v.rbegin(),v.rbegin()+k,0);
// }
// cout<<sum<<endl;