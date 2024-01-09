#include <bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

vector<int> levelOrder(node* root) {
    vector<int> ans; 
    if(root == NULL) 
        return ans; 
    queue<node*> q; 
    q.push(root); 
    
    while(!q.empty()) {
        
        node *temp = q.front(); 
        q.pop(); 
        
        if(temp->left != NULL) 
            q.push(temp->left); 
        if(temp->right != NULL) 
            q.push(temp->right); 
            
        ans.push_back(temp->data); 
    }
    return ans; 
}
    
vector<int> levelOrder(node* root) {
    vector<int> ans; 
    
    if(root == NULL) 
        return ans; 
        
    queue<node*> q; 
    q.push(root); 
    
    while(!q.empty()) {
        
        node *temp = q.front(); 
        q.pop(); 
        
        if(temp->left != NULL) 
            q.push(temp->left); 
        if(temp->right != NULL) 
            q.push(temp->right); 
            
        ans.push_back(temp->data); 
    }
    return ans; 
}

int maxDepth(node* root) {
    if(root == NULL) return 0; 
    
    int lh = maxDepth(root->left); 
    int rh = maxDepth(root->right); 
    
    return 1 + max(lh, rh); 
}
    
class diameterOfBinaryTreeClass {
public:
    int diameterOfBinaryTree(node* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    int height(node* node, int& diameter) {

        if (!node) {
            return 0;
        }

        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }
};

class isBalancedClass {

public:
    bool isBalanced(node* root) {
        return dfsHeight (root) != -1;
    }

    int dfsHeight (node *root) {

        if (root == NULL) return 0;
        
        int leftHeight = dfsHeight (root -> left);

        if (leftHeight == -1) 
            return -1;
        
        int rightHeight = dfsHeight (root -> right);

        if (rightHeight == -1) 
            return -1;
        
        if (abs(leftHeight - rightHeight) > 1)  
            return -1;

        return max (leftHeight, rightHeight) + 1;
    }
};

node* lowestCommonAncestor(node* root, node* p, node* q) {
    //base case
    if (root == NULL || root == p || root == q) {
        return root;
    }
    node* left = lowestCommonAncestor(root->left, p, q);
    node* right = lowestCommonAncestor(root->right, p, q);

    //result
    if(left == NULL) {
        return right;
    }
    else if(right == NULL) {
        return left;
    }
    else { //both left and right are not null, we found our result
        return root;
    }
}
    
bool isIdentical(node * node1, node * node2) {
  if (node1 == NULL && node2 == NULL)
    return true;
  else if (node1 == NULL || node2 == NULL)
    return false;

  return ((node1 -> data == node2 -> data) && isIdentical(node1 -> left, node2 -> left) && isIdentical(node1 -> right, node2 -> right));
}

vector<vector<int>> zigzagLevelOrder(node* root) {
    vector<vector<int>> ans;
    if (root==NULL) return ans;
    bool l2r = false;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        l2r = (!l2r);
        int sz= q.size();
        vector<int> v;
        for (int i=0; i<sz; i++){
            auto it = q.front();
            q.pop();
            if (it->left)q.push(it->left);
            if (it->right)q.push(it->right);
            v.push_back(it->data);
        }
        if (!l2r)reverse(v.begin(),v.end());
        ans.push_back(v);
    }
    return ans;
}

// boundary traversal of a binary tree

class boundaryTraversal{
public:
    bool isLeaf(node * root) {
        return !root -> left && !root -> right;
    }

    void addLeftBoundary(node * root, vector < int > & res) {
        node * cur = root -> left;
        while (cur) {
            if (!isLeaf(cur)) res.push_back(cur -> data);
            if (cur -> left) cur = cur -> left;
            else cur = cur -> right;
        }
    }
    
    void addRightBoundary(node * root, vector < int > & res) {
        node * cur = root -> right;
        vector < int > tmp;
        while (cur) {
            if (!isLeaf(cur)) tmp.push_back(cur -> data);
            if (cur -> right) cur = cur -> right;
            else cur = cur -> left;
        }
        for (int i = tmp.size() - 1; i >= 0; --i) {
            res.push_back(tmp[i]);
        }
    }

    void addLeaves(node * root, vector < int > & res) {
        if (isLeaf(root)) {
            res.push_back(root -> data);
            return;
        }
        if (root -> left) addLeaves(root -> left, res);
        if (root -> right) addLeaves(root -> right, res);
    }

    vector < int > printBoundary(node * root) {
        vector < int > res;
        if (!root) return res;

        if (!isLeaf(root)) res.push_back(root -> data);

        addLeftBoundary(root, res);

        // add leaf nodes
        addLeaves(root, res);

        addRightBoundary(root, res);
        return res;
    }
};

int main(){
  return 0;
}