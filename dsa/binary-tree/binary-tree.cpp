#include <bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

// inorder-iterative

vector < int > inorderTraversal(node * root) {
  
  vector < int > inorder;
  node * cur = root;
  
  while (cur != NULL) {
    if (cur -> left == NULL) {
      inorder.push_back(cur -> data);
      cur = cur -> right;
      
    } else {
      node * prev = cur -> left;
      
      while (prev -> right != NULL && prev -> right != cur) {
        prev = prev -> right;
      }

      if (prev -> right == NULL) {
        prev -> right = cur;
        cur = cur -> left;
      } else {
        prev -> right = NULL;
        inorder.push_back(cur -> data);
        cur = cur -> right;
      }
    }
  }
  return inorder;
}

// preorder-iterative

vector < int > preorderTraversal(node * root) {
  
  vector < int > preorder;
  node * cur = root;
  
  while (cur != NULL) {
    
    if (cur -> left == NULL) {
      preorder.push_back(cur -> data);
      cur = cur -> right;
      
    } else {
      
      node * prev = cur -> left;
      
      while (prev -> right != NULL && prev -> right != cur) {
        prev = prev -> right;
      }

      if (prev -> right == NULL) {
        prev -> right = cur;
        preorder.push_back(cur -> data);
        cur = cur -> left;
      } else {
        prev -> right = NULL;
        cur = cur -> right;
      }
    }
  }
  return preorder;
}

class rightViewOfBinaryTree {
public:
    void recursion(node *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()==level) res.push_back(root->data);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
        
        // for left view simply call left first then right
    }
    
    vector<int> rightSideView(node *root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};

class bottomViewClass {
  public:
    vector <int> bottomView(node *root) {
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            node* node = it.first; 
            int line = it.second; 
            mpp[line] = node->data; 
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans;  
    }
};

class topViewClass{
  public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(node *root)
    {
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            node* node = it.first; 
            int line = it.second; 
            if(mpp.find(line) == mpp.end()) mpp[line] = node->data; 
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans; 
    }
  
};


void allTraversal(node * root, vector < int > & pre, vector < int > & in , vector < int > & post) {
  stack < pair < node * , int >> st;
  st.push({root,1});
  
  if (root == NULL) return;

  while (!st.empty()) {
    auto it = st.top();
    st.pop();

    // this is part of pre
    // increment 1 to 2 
    // push the left side of the tree
    if (it.second == 1) {
      pre.push_back(it.first -> data);
      it.second++;
      st.push(it);

      if (it.first -> left != NULL) {
        st.push({it.first -> left,1});
      }
    }

    // this is a part of in 
    // increment 2 to 3 
    // push right 
    else if (it.second == 2) {
      in .push_back(it.first -> data);
      it.second++;
      st.push(it);

      if (it.first -> right != NULL) {
        st.push({it.first -> right,1});
      }
    }
    // don't push it back again 
    else {
      post.push_back(it.first -> data);
    }
  }
}

int main(){
  return 0;
}