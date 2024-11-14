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

vll vv(3*1e5,1);
void solve(){
    in(n)
    if (n%2){
        cout<<n<<endl;
        cout<<"2 1 3 4 5 ";
        f(i,6,n+1)cout<<i<<" ";
        cout<<endl;
        return;
    }
    ll i=2;
    while (i*2<=n)i=i*2;
    i--;
    // cout<<"i"<<" "<<i<<endl;
    vll v(n+1,0);
    set<ll> st;
    if (n%2==0){
        v[n]=i;
        v[n-2]=n;
        v[n-1]=1;    
        // v[1]=2;
        // v[2]=1;
        st.insert(1);
        // st.insert(2);
        st.insert(i);
        st.insert(n);
    }else{
        v[n]=n-1;
        v[n-1]=n;
        v[1]=2;
        v[2]=1;
        st.insert(n);
        st.insert(1);
        st.insert(2);
        st.insert(n-1);
    }
    ll x=2;
    i=1;
    while(i<n+1){
        if (v[i]==0) {
            if (st.find(x)==st.end()){
                v[i]=x; x++;
                i++;
            }else{
                x++;
            }
        }else i++;
    }
    ll c=0;
    f(i,1,n+1){
        if (i%2==0) {
            c=(c|v[i]);
        }else{
            c=(c&v[i]);
        }
        cout<<c<<" ";
    }
    cout<<c<<endl;
    f(i,1,n+1)cout<<v[i]<<" ";
    cout<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}