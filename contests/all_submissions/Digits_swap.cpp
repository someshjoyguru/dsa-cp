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
#define pYES cout<<'YES'<<endl;
#define pNO cout<<'NO'<<endl;

void solve(){
    in(n) in(k)
    ll sz=((ll)log10(n)+1);
    set<vll> st;
    ll tmp=n;
    ll id=sz-1;
    while(tmp){
        st.insert({tmp%10,id});
        tmp/=10;
        id--;
    }
    string s=to_string(n);
    ll i=0;
    if (k>=sz){
        sort(s);
        reverse(all(s));
        cout<<s;
        return;
    }
    // cout<<st.size()<<endl;
    // cout<<s<<endl;
    while(!st.empty() && k>0 && i<sz){
        auto it = (*st.rbegin());
        st.erase(it);
        if (it[0]>(s[i]-'0')){
            swap(s[i], s[it[1]]);
            st.insert({s[it[1]]-'0', it[1]});
            k--;
        }
        i++;
    }
    cout<<s;
}

int main(){
    fast;
    int t=1;
    // cin >> t;
    while(t--)solve();
}