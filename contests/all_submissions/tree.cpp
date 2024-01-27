#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node {
    ll data;
    node *left, *right;
};

node* newNode(ll data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

node* insert(node* root, ll data){
    if (root==NULL) return newNode(data);
    else if (data>root->data) root->right = insert(root->right, data);
    else root->left=insert(root->left, data);
    return root;
}

void inorder(node* root){
    if (root==NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    ll t=1;
    // cin >> t;
    node* root=NULL;
    root=insert(root, 5);
    root=insert(root, 7);
    root=insert(root, -5);
    root=insert(root, 8);
    root=insert(root, 3);
    root=insert(root, 1);
    root=insert(root, 4);
    root=insert(root, 2);
    inorder(root);
    return 0;
}