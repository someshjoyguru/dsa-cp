#include<bits/stdc++.h> 
using namespace std; 
int main(){ 
long long t=1; 
 cin>>t; 
 while(t--){ 
     int n; 
     cin>>n; 
     long long a[n]; 
     unordered_map<long,long>m; 
     set<pair<long long,long long>>s; 
     for(long long i=0;i<n;i++){ 
         cin>>a[i]; 
         m[a[i]]++; 
         s.insert({i,a[i]}); 
          
     } 
        vector<long long>an; 
     for(auto &i:s){ 
         if(m[i.second]>1){ 
             continue; 
             
         } 
         an.push_back(i.second); 
          
     } 
     if(an.empty()){ 
         cout<<0<<endl; 
         continue; 
     } 
     int cnt=0; 
     for(long long i=1;i<an.size()-1;i++){ 
         if(an[i]<an[i+1]){ 
             cnt++; 
         } 
          
     } 
     cout<<cnt<<endl; 
    
    
 } 
 
 return 0; 
}
