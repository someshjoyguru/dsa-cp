#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(n)for (ll z=0; z<n; z++)
#define f1(z,n)for (ll z=0; z<n; z++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define inv(v,n) vll v(n); f(n)cin>>v[z];
#define pura(v) v.begin(),v.end()
#define sort(v) sort(pura(v));

void solve(){
    in(n);
    inv(v,n);
    map<ll,ll> mp;
    // ll maxval=INT_MIN;
    for (ll i=0; i<n; i++){
        mp[v[i]]++;
        // maxval=max(maxval,v[i]);
    }
    ll maxi=INT_MIN;
    bool flag=1;
    
    ll lastnon1=0;
    for (auto x : mp){
        if (flag && x.second==1 && x.first-lastnon1==1){
            cout<<-1<<endl;
            return;
        }
        if (flag && x.first-lastnon1>1)flag=0;
        maxi=max(maxi,x.second);
        if (flag && x.second!=1)lastnon1=x.first;
    }
    // cout<<last<<endl;
    maxi=0;
    for (int i=0; i<n; i++){
        maxi+=(lastnon1==v[i]);
    }
    
    cout<<lastnon1<<" it is"<<endl;
    cout<<maxi<<endl;
    ll start=0;
    for (ll i=0; i<n; i++){
        if (v[i]==lastnon1){
            cout<<start+1<<" "<<i+1<<endl;
            start=i;
        }
    }

    // ll start=0;
    // ll end=0;
    // set<ll> st;
    
    // for (int i=0; i<n; i++){
    //     st.insert(v[i]);
    //     if (st.size()<=i-start){
    //         cout<<start+1<<" "<<i<<endl;
    //         st.clear();
    //         st.insert(v[i]);
    //         start=i;
    //     }
    // }
    cout<<start+1<<" "<<n<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}