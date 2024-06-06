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
    vin(x,n)
    vin(p,n)
    vector<vll> v;
    vll visil(n,0);
    vll visir(n,0);
    ll temp=1;
    visil[0]=temp;
    f(i,1,n){
        if (x[i-1]+p[i-1]>=x[i]){
            visil[i]=temp;
        }else{
            temp++;
            visil[i]=temp;
        }
    }

    temp=1;
    visir[n-1]=temp;
    for (int i=n-2; i>=0; i--){
        if (x[i+1]-p[i+1]<=x[i]){
            visir[i]=temp;
        }else{
            temp++;
            visir[i]=temp;
        }
    }

    if (visil[n-1]<=2 || visir[0]<=2){
        cout<<"YES"<<endl;
        return;
    }
    int start=n-1, last=0;
    while (last<n-1){
        if (visir[last]==visir[last+1]) last++;
        else break;
    }
    while (start>0){
        if (visil[start]==visil[start-1]) start--;
        else break;
    }
    // cout<<start<<" "<<last<<endl;
    if (start-last<=1){
        cout<<"YES"<<endl;
        return;
    }

    start=n-1, last=0;
    while (last<n-1){
        if (visil[last]==visil[last+1]) last++;
        else break;
    }
    while (start>0){
        if (visir[start]==visir[start-1]) start--;
        else break;
    }
    // cout<<start<<" "<<last<<endl;
    if (start-last<=1){
        cout<<"YES"<<endl;
        return;
    }


    cout<<"NO"<<endl;
    // f(i,0,n)cout<<visil[i]<<" ";
    // cout<<endl;
    // f(i,0,n)cout<<visir[i]<<" ";
    // cout<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}