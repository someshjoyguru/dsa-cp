#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
    int data;
    node* left;
    node* right;
    node* nextRight;
    node(ll data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
        this->nextRight=NULL;
    }
};

// create this :
// setting right pointer to next right node
/*
        10 ----------> NULL
    /  \
    8 --->2 --------> NULL
    /
3 ----------------> NULL
*/
void connect(node* root){
    if (root==NULL)return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        ll sz= q.size();
        node* prev=NULL;
        while(sz--){
            node* temp=q.front();
            q.pop();

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
            if (prev) prev->nextRight=temp;
            prev=temp;
        }
        prev->nextRight=NULL;
    }
}

// search in BST
struct node* search(node* root,ll key){
    if (root==NULL || root->data==key) return root;
    if (root->data>key) return search(root->left,key);
    else if (root->data<key) return search(root->right,key);
}

// preorder to bst

node* pretoBST(vector<ll>& pre){
    ll i=0;
    return buildBST(pre,i,INT_MAX);
}

node* buildBST(vector<ll>& pre, ll &i, ll bound){
    if (i==pre.size() || pre[i]>bound) return NULL;
    node* temp = new node(pre[i]);
    i++;
    temp->left=buildBST(pre,i,temp->data);
    temp->right=buildBST(pre,i,bound);
    return temp;
}

//




int main(){
    return 0;
}