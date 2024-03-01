#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll win=-1;
bool canWin(int n, int a, int b, int ch) {
    // Base case: If there are no stones left, the current player loses.
    if (n <= 0) {
        return false;
        win=1-ch;
    }
    
    // Check if the current player can force the opponent into a losing position.
    if (ch==1){
        for (int i = 1; i <= a; ++i) {
            if (!canWin(n - i, a, b,0)) {
                return true;
            }
        }
    }else{
        for (int i = 1; i <= b; ++i) {
            if (!canWin(n - i, a, b,1)) {
                return true;
            }
        }
    }
    
    // If the current player cannot force the opponent into a losing position, they lose.
    return false;
}

string predictWinner(int n, int a, int b) {
    if (canWin(n, a, b,1)) {
        return "Alice";
    } else {
        return "Bob";
    }
}

void solve(){
    ll n,a,b;
    cin>>n>>a>>b;
    win=-1;
    if (a>=n){
        cout<<"Alice"<<endl;
        return;
    }
    cout<<predictWinner(n,a,b)<<endl;
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--) solve();
}
