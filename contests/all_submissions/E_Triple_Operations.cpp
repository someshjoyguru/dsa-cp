#include <bits/stdc++.h>
using namespace std;

int f(vector<int>&arr,int n){
    int level = 0;

  int cnt = 0;
  int c=0;
  vector<int>l(n,0);
    for(int i=0;i<n;i++){
        if(pow(2,level)<i-c){
            if(arr[i]%2==0){
                cnt++;
            }
        }
        else{
            l[level]=cnt;
            cnt=0;
            c=i-1;
        }
    }
    int ans=0;level=1;
    for(int i=0;i<n;i++){
        if(l[i]>ans){
            ans=l[i];
            level=i+1;
        }
    }
    return level;
}
int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}