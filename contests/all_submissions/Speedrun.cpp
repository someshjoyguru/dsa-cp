#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(i,a,b) for (ll (i)=(a); (i)<(b); (i)++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define sin(s) string (s); cin>>(s);
#define vin(v,n) vll (v)(n); f(i,0,n)cin>>(v)[i];
#define all(v) (v).begin(),(v).end()
#define sort(v) sort(all(v));
#define pYES cout<<"YES"<<endl;
#define pNO cout<<"NO"<<endl;

void solve(){
    in(n) in(k)
    vin(a, n)
    vin(h, n)
    // minheap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // {cor, health}
    map<int, int> mp;
    f(i,0,n){
        mp[a[i]]+=h[i];
    }
    for (auto it: mp){
        pq.push({it.first, it.second});
    }
    ll time=0;
    ll balance=1;
    ll healthDestroyed = 0;
    ll bombstart=0;

    bool fl=false, fll=false;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        ll nearest = it.first;
        ll nearestHealth = it.second;
        balance = nearest - healthDestroyed;
        if (fl){
            if (nearest-bombstart<= 2*k){
                continue;
            }else{
                fl = false;
            }
        }
        if (nearestHealth>balance){
            // bomb plant
            // nearest se nearest + 2k
            if (fll){
                cout<<"NO"<<endl;
                return;
            }
            bombstart=nearest;
            fl=true;
            fll=true;
        }else{
            healthDestroyed+=nearestHealth;
        }
    }
    cout<<"YES"<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}