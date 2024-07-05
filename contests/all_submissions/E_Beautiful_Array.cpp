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
    in(n) in(k)
    vin(a,n);
     
    map<int,set<int>>mp; 
    for(int x:a){ 
        if(mp[x%k].find(x)!=mp[x%k].end()){ 
            mp[x%k].erase(x); 
        }else{ 
            mp[x%k].insert(x); 
        } 
    } 
    int cnt=0,val=-1; 
    for(auto x:mp){ 
        int sz=x.second.size(); 
        if(sz%2){ 
            cnt++; 
            val=x.first; 
        } 
    } 
    if(cnt>1){ 
        cout<<-1<<endl; 
        return; 
    } 
    int ans=0; 
    bool flg=false; 
    for(auto x:mp){ 
        if(x.==val){ 
            continue; 
        } 
        while(x.second.size()>0){ 
            int b=*x.second.begin(); 
            x.second.erase(b); 
            int tp=*x.second.begin(); 
            ans+=(tp-b)/k; 
            x.second.erase(tp);             
        } 
    } 
    //deb(ans); 
    if(cnt){ 
        vll v; 
        for(int x:mp[val]){ 
            v.push_back(x); 
        } 
        //pv(v); 
        int n=v.size(); 
        if(n==1){ 
            cout<<ans<<endl; 
            return; 
        } 
        vll pref(n,0),suf(n,0); 
        pref[1]=v[1]-v[0]; 
        for(int i=3;i<n-1;i++){ 
            pref[i]=v[i]-v[i-1]+pref[i-2]; 
        } 
        suf[n-2]=v[n-1]-v[n-2]; 
        for(int i=n-4;i>=0;i--){ 
            suf[i]=v[i+1]-v[i]+suf[i+2]; 
        } 
        int ta=LLONG_MAX; 
        for(int i=0;i<n;i+=2){ 
            int x=0; 
            if(i>0){ 
                x+=pref[i-1]; 
            } 
            if(i+1<n){ 
                x+=suf[i+1]; 
            } 
            ta=min(ta,x); 
        } 
        ans+=ta/k; 
    } 
    cout<<ans<<endl; 
}

int main(){
    fast;
    int t=1;
    cin >> t;
    while(t--)solve();
}

int n,m;
  cin>>n>>m;
  int a[n][m];
  for(int i=0;i<n;i++){
   for(int j=0;j<m;j++){
    cin>>a[i][j];
   }
  }
  for(int i=0;i<n;i++){
   for(int j=0;j<m;j++){
    
   }
  }
  
  
  for(int i=0;i<n;i++){
   for(int j=0;j<m;j++){
    cout<<a[i][j]<<" ";
   }
   cout<<endl;
  }
}