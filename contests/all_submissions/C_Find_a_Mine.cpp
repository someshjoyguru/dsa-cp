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

void query(int a,int b){
    cout<<"? "<<a<<" "<<b<<endl;
    cout.flush();
    return;
}
// void solve(){
//     int n;cin>>n;
//     //first i will try to find maximum number 
//     // int maxi=0;
//     // for (int i=1;i<n;i++){
//     //     query(maxi,maxi,i,i);
//     //     char reply;cin>>reply;
//     //     if(reply=='<'){
//     //         maxi=i;
//     //     }
//     // }
//     //query gives me result for maximum ORs
//     //but i want maximum XOR
//     //so i will store all the possible ans giving maxOR
//     vector<int> possAns;
//     int j=0;
//     possAns.push_back(j);
//     for (int i=1;i<n;i++){
//         query(maxi,j,maxi,i);
//         char reply;cin>>reply;
//         if(reply=='='){
//             possAns.push_back(i);
//         }
//         else if(reply=='<'){
//             j=i;
//             possAns.clear();
//             possAns.push_back(i);
//         }
//     }
//     // now by observation
//     //my maxi is 12 1100
//     //possAns 1011 1111 0011 0111
//     //maxXOR will be given by minimum of possAns
//     int mini=possAns[0];
//     for (int i=0;i<possAns.size();i++){
//         query(mini,mini,i,i);
//         char reply;cin>>reply;
//         if(reply=='>'){
//             mini=i;
//         }
//     }
//     cout<<"! "<<maxi<<" "<<mini<<endl;
//     cout.flush();
// }

void solve(){
    in(n);
    in(m);
    
    ll diag=n+m-1;
    ll mini=
    query(1,1);
    ll reply;cin>>reply;
    if(reply==0){
        cout<<"!"<<" "<<1<<" "<<1<<endl;
        cout.flush();
        return;
    }
    query

    



    cout.flush();
}

int main(){
    // fast;
    int t=1;
    cin >> t;
    while(t--)solve(),fflush(stdout);
}