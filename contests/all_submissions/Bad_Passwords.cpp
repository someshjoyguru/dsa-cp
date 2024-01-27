#include <bits/stdc++.h>
using namespace std;
#define ll long long

string pre="";
string suf="";
string s2pre="";
string s2suf="";
ll check(string s, vector<vector<string>>& v){
    for (ll i=0; i<v.size(); i++){
        for (ll j=0; j<v[i].size(); j++){
            auto f = s.find(v[i][j]);
            if (f!=string::npos){
                pre=s.substr(0,f);
                suf=s.substr(f+v[i][j].size());
                return i;
            }
        }
    }
    return -1;
}

bool check2(string s, vector<string>& v){
    for (ll i=0; i<v.size(); i++){
        auto f = s.find(v[i]);
        if (f!=string::npos){
            s2pre=s.substr(0,f);
            s2suf=s.substr(f+v[i].size());
            return true;
        }
    }
    return false;
}

void solve(){
    ll n;
    cin >> n;
    vector<vector<string>> v(n);
    string s;
    for (ll i=0; i<n; i++){
        ll m;
        cin >> m;
        vector<string> v1(m);
        for (ll j=0; j<m; j++){
            cin >> s;
            v1[j] = s;
        }
        v[i] = v1;
    }
    ll q;
    cin >> q;
    while(q--){
        string s1, s2;
        cin >> s1 >> s2;

        bool s1s2 = false;
        bool s2s1 = false;

        // check s1 then s2
        pre="";suf="";
        ll ind=check(s1,v);
        if (ind==-1){
            // cout << "OK" << endl;
            s1s2=false;
        }else{
            if(check2(s2,v[ind])){
                if (pre==s2pre && suf==s2suf){
                    // cout << "REJECT" << endl;
                    s1s2=true;
                }else{
                    // cout << "OK" << endl;
                    s1s2=false;
                }
            }
        }

        // check s2 then s1
        pre="";suf="";
        ind=check(s2,v);
        if (ind==-1){
            // cout << "OK" << endl;
            s2s1=false;
        }else{
            if(check2(s1,v[ind])){
                if (pre==s2pre && suf==s2suf){
                    // cout << "REJECT" << endl;
                    s2s1=true;
                }else{
                    // cout << "OK" << endl;
                    s2s1=false;
                }
            }
        }

        if (!s1s2 && !s2s1){
            cout << "OK" << endl;
        }else{
            cout << "REJECT" << endl;
        }

    }
}

int main(){
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}


