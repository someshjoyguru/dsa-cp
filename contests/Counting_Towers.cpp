#include <bits/stdc++.h>
using namespace std;
#define  fastio()        ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define ln '\n'

const int nax = 1e6+10;
const int mod = 1e9+7;


int main(){
    vector<vector<ll>> numberOfTowers (nax,vector<ll>(8,0));
    for(int i = 0; i < 8; i++)
        numberOfTowers[0][i] = 1;
    for (int i = 1; i <nax;i++){
        for(int j=0; j < 8; j++){
            if (j == 0 || j == 2 || j == 3 || j == 4 || j == 5)
                numberOfTowers [i][j] = (numberOfTowers [i-1][0]+ numberOfTowers [i-1][1]+ numberOfTowers [i-1][3]+ numberOfTowers [i-1][4]+numberOfTowers [i-1][5])%mod;
                else{
                    numberOfTowers[i][j]= (numberOfTowers [i-1][2]+ numberOfTowers [i-1][6]+numberOfTowers [i-1][7])%mod;
                }
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<(numberOfTowers [n-1][2]+ numberOfTowers [n-1][6])%mod<<endl;
    }
}