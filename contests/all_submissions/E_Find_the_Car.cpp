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
    ll n,k,q;
    cin>>n>>k>>q;
    vector<ll> a(k), b(k), que(q);
    for (ll i=0; i<k; i++)cin>>a[i];
    for (ll i=0; i<k; i++)cin>>b[i];
    for (ll i=0; i<q; i++)cin>>que[i];
    for (auto d: que){
        ll ans=0, i=0;
        float sp=(float)a[0]/(float)b[0];
        if (d<a[0]){
            // cout<<d<<" ";
            // cout<<sp<<" ";
            // cout<<d/(int)sp<<" ";
            if (sp==(int)sp)cout<<floor((int)d/(int)sp)<<" ";
            else cout<<floor((float)d/(float)sp)<<" ";
            continue;
        }
        ll mini=INT_MAX;
        int f=0;
        while (i<n && a[i]<=d){
            if (a[i]==d){
                cout<<b[i]<<" ";
                f=1;
                break;
            }
            mini=i;
            i++;
        }
        if (f)continue;
        if (mini==INT_MAX){
            cout<<floor((float)d/sp)<<" ";
            continue;
        }
        sp=(float)(a[mini+1]-a[mini])/(float)(b[mini+1]-b[mini]);
        cout<< fixed << setprecision(0)<<b[mini]+floor((float)(d-b[mini])/sp)<<" ";
    }
    cout<<endl;
}
void solve1(){
    ll n,k,q;
    cin>>n>>k>>q;
    inv(a,k);
    inv(b,k);
    for (int x=0; x<q; x++){
        ll d; cin>>d;
        ll ans=0, sp=a[0]/b[0], i=0;
        if (d<a[0]){
            cout<<d/sp<<" ";
            continue;
        }
        ll mini=INT_MAX;
        while (i < k && a[i] <= d){
            if (a[i] == d){
                cout<<b[i]<<" ";
                continue;
            }
            mini=i;
            i++;
        }
        if (i < k) {
            sp=(a[i]-a[mini])/(b[i]-b[mini]);
            cout<<b[mini]+(d-a[mini])/sp<<" ";
        } else {
            cout<<b[k-1]+(d-a[mini])/(a[mini]-a[mini-1])<<" ";
        }
    }
    cout<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}