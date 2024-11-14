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
    in(n)
    sin(s)
    if (n%2==0){
        map<char,ll> mpe, mpo;
        f(i,0,n) if (i&1) mpe[s[i]]++; else mpo[s[i]]++;
        ll maxio=0, maxie=0;
        for (auto it: mpe) maxie=max(maxie, it.second);
        for (auto it: mpo) maxio=max(maxio, it.second);
        cout<<n-maxie-maxio<<endl;
    }else{
        ll mini=1e9;
        map<char,ll> mpe, mpo, mpee, mpoo;
        f(i,0,n){
            if (i&1){
                mpe[s[i]]++;
            }else mpo[s[i]]++;
        }
        for (ll i=n-1; i>=0; i--){
            if (i%2){
                //even talks
                mpe[s[i]]--;
                map<char, ll> tmpe, tmpo;
                for (auto it: mpee) tmpo[it.first]+=it.second;
                for (auto it: mpoo) tmpe[it.first]+=it.second;
                for (auto it: mpe) tmpe[it.first]+=it.second;
                for (auto it: mpo) tmpo[it.first]+=it.second;
                ll maxio=0, maxie=0;
                for (auto it: tmpe) maxie=max(maxie, it.second);
                for (auto it: tmpo) maxio=max(maxio, it.second);
                mini=min(mini,n-maxie-maxio);
                mpee[s[i]]++;
            }else{
                //odd talks
                mpo[s[i]]--;
                map<char, ll> tmpe, tmpo;
                for (auto it: mpee) tmpo[it.first]+=it.second;
                for (auto it: mpoo) tmpe[it.first]+=it.second;
                for (auto it: mpe) tmpe[it.first]+=it.second;
                for (auto it: mpo) tmpo[it.first]+=it.second;
                ll maxio=0, maxie=0;
                for (auto it: tmpe) maxie=max(maxie, it.second);
                for (auto it: tmpo) maxio=max(maxio, it.second);
                mini=min(mini,n-maxie-maxio);
                mpoo[s[i]]++;
            }
        }
        cout<<mini<<endl;
    }
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}