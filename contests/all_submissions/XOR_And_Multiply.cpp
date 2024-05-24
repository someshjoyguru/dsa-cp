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

void seedRandom() {
    srand(time(NULL));
}

int randomValue() {
    return (rand() % 1000000000) + 1;
}
vector<int> findNumbers(int N) {
    for (int i = 1; i <= N+10000; ++i) {
        for (int j = i; j <= N+10000; ++j) {
            if ((i & j) % N == 0 && (i ^ j) % N == 0 && (i&j!=0)) {
                return {i, j};
            }
        }
    }
    return {-1, -1}; 
}

void solve(){
    // ll n=randomValue();
    in(n);
    // cout<<n<<endl;
    // ll a=n, b=(a|1);
    // for (;;a<<1){
    //     if ((a&b)%n==0 and (a^b)%n==0){
    //         cout<<"a and b : "<<a<<" "<<b<<endl;
    //         cout<<"and xor : "<<(a&b)<<" "<<(a^b)<<endl;
    //         return;
    //     }
    // }
    auto y=findNumbers(n);
    cout<<"a and b : "<<y[0]<<" "<<y[1]<<endl;
}

int main(){
    fast;
    seedRandom();
    int t=100;
    cin >> t;
    while(t--)solve();
}