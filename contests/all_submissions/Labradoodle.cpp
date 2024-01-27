#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n,m;
    cin>>n>>m;
    vector<string> word;
    vector<string> mix;
    string s="";
    for (ll i=0; i<n; i++){
        cin>>s;
        word.push_back(s);
    }
    for (ll i=0; i<m; i++){
        cin>>s;
        mix.push_back(s);
    }

    for (ll i=0; i<m; i++){
        s=mix[i];
        if (s.size()<3){
            cout<<"none"<<endl;
            continue;
        }
        string mixpre=s.substr(0,3);
        string mixsuf=s.substr(s.size()-3,3);
        vector<string> pre;
        vector<string> suf;
        for (ll j=0; j<n; j++){
            if (word[j].size()<3){
                continue;
            }
            string wordpre=word[j].substr(0,3);
            string wordsuf=word[j].substr(word[j].size()-3,3);
            if (wordpre==mixpre){
                pre.push_back(word[j]);
            }
            if (wordsuf==mixsuf){
                suf.push_back(word[j]);
            }
        }
        if (pre.size()==0 || suf.size()==0){
            cout<<"none"<<endl;
        }
        else if (pre.size()==1 && suf.size()==1){
            cout<<pre[0]<<" "<<suf[0]<<endl;
        }
        else if (pre.size()>1 || suf.size()>1){
            cout<<"ambiguous"<<endl;
            continue;
        }
        pre.clear();
        suf.clear();
    }
    return 0;
}