#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long
/*
0 1 3
Pattern : Circular Rotation
neglect it : (0 1 3 {2})
operation starts:
operation 1:
{
    2 1 3
    2 0 3
    2 0 1
}

operation 2:
{
    3 2 0
}
...... (given)
1 2 3 4 5 6
5 6 1 2 3 4
        n n+1


k=k%(n+1);
cout<< k -> n+1
then cout 1 -> k-2
operation k:
{

}



*/
void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n+1);
    ll sum=0;
    for (ll i=0; i<n; i++){
        cin>>v[i];
        sum+=v[i];
    }
    ll mis=n*(n+1)/2-sum;
    v[n]=mis;
    k=k%(n+1);
    for (int i=n-k+1; i<n+1; i++)cout<<v[i]<<" ";

    // n-(n-n+k-1)
    for (int i=0; i<n-k; i++)cout<<v[i]<<" ";
    cout<<endl;
}

int main(){
    fastio()
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}