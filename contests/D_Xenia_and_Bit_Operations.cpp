#include <bits/stdc++.h>
using namespace std;
#define ll long long

class SGTree {
public:
	vector<int> seg;
	SGTree(int n) {
		seg.resize(4 * n + 1,0);
	}

    void printRootNode(){
        cout<<seg[0]<<endl;
    }

	void build(int ind, int low, int high, int arr[], bool orr) {
		if (low == high) {
			seg[ind] = arr[low];
			return;
		}

		int mid = (low + high) / 2;
		build(2 * ind + 1, low, mid, arr, !orr);
		build(2 * ind + 2, mid + 1, high, arr, !orr);
		if (orr) seg[ind]=seg[2*ind+1] | seg[2*ind+2];
        else seg[ind]=seg[2*ind+1] ^ seg[2*ind+2];
	}

	void update(int ind, int low, int high, int i, int val,bool orr) {
		if (low == high) {
			seg[ind] = val;
			return;
		}

		int mid = (low + high) >> 1;
		if (i <= mid) update(2 * ind + 1, low, mid, i, val, !orr);
		else update(2 * ind + 2, mid + 1, high, i, val, !orr);
		if (orr) seg[ind]=seg[2*ind+1] | seg[2*ind+2];
        else seg[ind]=seg[2*ind+1] ^ seg[2*ind+2];
	}
};


// if n is even first xor
// else first or 

int main(){
    ll n,q;
    cin>>n>>q;
    int ele = pow(2,n);
    int v[ele]={0};
    SGTree sg(ele);
    for (ll i=0; i<ele;i++)cin>>v[i];
    if (n%2) sg.build(0,0,ele-1,v,true);
    else sg.build(0,0,ele-1,v,false);
    // for (ll i=0; i<4*ele; i++)cout<<sg.seg[i]<<" ";
    cout<<endl;
    while(q--){
        ll x,y;
        cin>>x>>y;
        x--;
        if (n%2) sg.update(0,0,ele-1,x,y,true);
        else sg.update(0,0,ele-1,x,y,false);
        cout<<sg.seg[0]<<endl;
    }
    return 0;
}