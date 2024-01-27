#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

ll incorrect(ll x, ll n){
    // ll x,n;
    // cin>>x>>n;
    ll z=x/n;
    ll i,c=1;
    for(i=1;i<=z;i++){
        if(x%i==0){
            c=i;
        }
    }
    return c;
}

ll correct(ll x, ll n){
    // ll x, n;
    // cin >> x >> n;
    ll k = x/n;
    set<ll> st;

    for (ll i = 1; i <= sqrt(x); i++){
        if (x % i == 0){
            st.insert(i);
            st.insert(x / i);
        }
    }
    ll temp=*st.begin();
    for (auto i : st){
        if (i>k){
            return temp;
        }
        if (i==k){
            return i;
        }
        temp=i;
    }
    return temp;
}
int main(){
    fastio()
    ll t=10;
    srand(time(0));
    // cin >> t;
    // while(t--){
    while(true){
        // srand(time(0));
        ll x = rand()%100000000 +1;
        ll n = rand()%100000000+1;
        while(x<n){
            // srand(time(0));
            n = rand()%100000000+1;
        }
        cout<<x<<" "<<n<<endl;
        ll a = correct(x,n);
        ll b =incorrect(x,n);
        // cout<<a<<" "<<b<<endl;
        if (a!=b){
            cout<<x<<" "<<n<<endl;
            return 0;
        }
    }
    return 0;
}