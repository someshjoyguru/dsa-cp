#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
    ll k;
    cin>>k;
    vector<ll> v(17);
    for (ll i=0; i<17; i++)v[i]=9*(i+1)*pow(10,i);
    ll digit_size=1;
    ll i=0;
    while(true){
        if (k-v[i]<=0)break;
        digit_size=i+2;
        k-=v[i];
        i++;
    }
    
    ll first_no = pow(10,digit_size-1);
    ll current_no = first_no + k/digit_size-1;
    k=k%digit_size;

    
    
    if (k==0){
        cout<<current_no%10<<endl;
        return;
    }
    ll shift_right=digit_size-k;
    current_no++;
    while(shift_right--){
        current_no=current_no/10;
    }
    cout<<current_no%10<<endl;
}

int main(){
    fastio()
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}