#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    vector<vector<ll>> mega(3*n, vector<ll>(3, 0));
    int k=0;
    for(ll i=0; i<n; i++){
        mega[i][0] = k;
        mega[i][1] = i;
        cin >> mega[i][2];
    }
    k++;
    for(ll i=n; i<2*n; i++){
        mega[i][0] = k;
        mega[i][1] = i-n;
        cin >> mega[i][2];
    }
    k++;
    for(ll i=2*n; i<3*n; i++){
        mega[i][0] = k;
        mega[i][1] = i-2*n;
        cin >> mega[i][2];
    }
    sort(mega.begin(), mega.end(), [](vector<ll> &a, vector<ll> &b){
        return a[2] > b[2];
    });

    // for (ll i = 0; i < 3*n; i++) {
    //     cout << mega[i][0] << " " << mega[i][1] << " " << mega[i][2] << endl;
    // }

    vector<ll> v(3, -1);
    map<ll, ll> mp;
    ll sum=0;
    // cout << endl;
    for (ll i = 0; i < 3*n; i++) {
        if (mp.find(mega[i][1]) != mp.end()) {
            continue;
        }
        if (v[mega[i][0]] == -1 ) {
            v[mega[i][0]] = mega[i][1];
            mp[mega[i][1]]++;
            // cout<<mega[i][0]<<" "<<mega[i][1]<<" "<<mega[i][2]<<endl;
            sum+=mega[i][2];
        }
        if (v[0] != -1 && v[1] != -1 && v[2] != -1) {
            break;
        }
    }
    cout << sum << endl;

}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}