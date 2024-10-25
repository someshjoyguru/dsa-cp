#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(i,v,b) for (ll (i)=(v); (i)<(b); (i)++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define sin(s) string (s); cin>>(s);
#define vin(v,n) vll (v)(n); f(i,0,n)cin>>(v)[i];
#define all(v) (v).begin(),(v).end()
#define sort(v) sort(all(v));
#define pYES cout<<"YES"<<endl;
#define pNO cout<<"NO"<<endl;

vll comp() {
    vll p;
    for (ll i = 0; (1 << i) - 1 <= 1000000000; ++i) {
        p.push_back((1 << i) - 1);
    }
    return p;
}

void solve(){
    in(n)
    vin(v,n)
    vll dp(32, 0);
    
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < 32; j++) {
            if(v[i] & (1 << j)) {
                dp[31-j]++;
            }
        }
    }
    // f(i,0,32)cout<<dp[i]<<" ";cout<<endl;
    vll hash(n, 0);
    for(ll i = 31; i >= 0; i--) {
        if (dp[31]==0){
            cout<<n<<endl;
            return;
        }
        if(dp[i] == 0) {

            for(ll j = i - 1; j >= 0; j--) {
                f(k,0,n) {
                    if(v[k] & (1 << (31-j))) {
                        hash[k] = 1;
                    }
                }
            }
            // cout<<endl;
            // f(i,0,n)cout<<hash[i]<<" ";cout<<endl;
            
            cout << accumulate(all(hash),0) << endl;
            return;
        }
    }
    cout<<n<<endl;
    return;
}

int main(){
    fast;
    vll p = comp();
    unordered_set<ll> st(p.begin(), p.end());
    ll t=1;
    cin >> t;
    while(t--){
        in(n)
        vin(v,n)
        ll orr = 0;
        for (ll i = 0; i < n; ++i) {
            orr |= v[i];
        }

        if (st.count(orr)) {
            cout << 0 << "\n";
            continue;
        }

        ll cnt = n;

        for (ll power : p) {
            if (power > orr) break;

            ll cur = 0;
            ll removals = 0;

            for (ll i = 0; i < n; ++i) {
                if ((cur | v[i]) <= power) {
                    cur |= v[i];
                } else {
                    ++removals;
                }
            }

            if (cur == power) {
                cnt = min(cnt, removals);
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}