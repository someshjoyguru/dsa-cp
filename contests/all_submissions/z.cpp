#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for (int i=0; i<=n; i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUParent(int node){
        if (node==parent[node]) return node;
        return parent[node]=findUParent(parent[node]);
    }

    void unionDisjointSet(int node1, int node2){
        int ultimateParent1=findUParent(node1);
        int ultimateParent2=findUParent(node2);
        if (ultimateParent1==ultimateParent2) return;
        if (size[ultimateParent1]>size[ultimateParent2]){
            size[ultimateParent1]+=size[ultimateParent2];
            parent[ultimateParent2]=ultimateParent1;
        }else{
            size[ultimateParent2]+=size[ultimateParent1];
            parent[ultimateParent1]=ultimateParent2;
        }
        return;
    }
};

int main(){
    DisjointSet ds(7);
    ds.unionDisjointSet(1, 2);
    ds.unionDisjointSet(2, 3);
    ds.unionDisjointSet(4, 5);
    ds.unionDisjointSet(6, 7);
    ds.unionDisjointSet(5, 6);
    // if 3 and 7 same or not
    if (ds.findUParent(3) == ds.findUParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionDisjointSet(3, 7);

    if (ds.findUParent(3) == ds.findUParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}