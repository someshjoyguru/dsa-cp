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

// vertical order traversal of binary tree - lc-hard

/*
Notes:
1. for storing the nodes with vertical and level
2. multiset is used to sort if their is more than one value
  in same vertical and level
  using set might remove same elements as the question
3. has repetitive elements condition too.
4. queue is used to do level order traversal
*/

vector<vector<int>> findVertical(node * root) {
  map<int,map<int,multiset<int>>> nodes;
  // vertical, <level, node_values>
  queue<pair<node*,pair<int,int>>> todo;
  // node, < vertical, level >
  todo.push({root,{0,0}}); // initial vertical and level
  while (!todo.empty()) {
    auto p = todo.front();
    todo.pop();
    node* temp = p.first;

    //x -> vertical , y->level
    int x = p.second.first, y = p.second.second;
    nodes[x][y].insert(temp -> data); //inserting to multiset

    if (temp -> left) {
      todo.push({temp -> left,{x - 1,y + 1}});
    }
    if (temp -> right) {
      todo.push({temp -> right,{x + 1,y + 1}});
    }
  }
  vector < vector < int >> ans;
  for (auto p: nodes) {
    // p: vertical, <level, node_values>
    vector < int > col;
    for (auto q: p.second) {
      // q: <level, node_values>
      col.insert(col.end(), q.second.begin(), q.second.end());
    }
    ans.push_back(col);
  }
  return ans;
}

// root to node path in binary tree

bool getPath(node * root, vector < int > & arr, int x) {
  // if root is NULL
  // there is no path
  if (!root)
    return false;

  // push the node's value in 'arr'
  arr.push_back(root -> data);

  // if it is the required node
  // return true
  if (root -> data == x)
    return true;

  // else check whether the required node lies
  // in the left subtree or right subtree of
  // the current node
  if (getPath(root -> left, arr, x) ||
    getPath(root -> right, arr, x))
    return true;

  // required node does not lie either in the
  // left or right subtree of the current node
  // Thus, remove current node's value from
  // 'arr'and then return false   
  arr.pop_back();
  return false;
}


int widthOfBinaryTree(node * root) {
  if (!root)
    return 0;
  int ans = 0;
  queue < pair < node * , int >> q;
  q.push({root,0});
  while (!q.empty()) {
    int size = q.size();
    int curMin = q.front().second;
    int leftMost, rightMost;
    for (int i = 0; i < size; i++) {
      int cur_id = q.front().second - curMin; // subtracted to prevent integer overflow
      node * temp = q.front().first;
      q.pop();
      if (i == 0) leftMost = cur_id;
      if (i == size - 1) rightMost = cur_id;
      if (temp -> left)
        q.push({temp -> left,cur_id * 2 + 1});
      if (temp -> right)
        q.push({temp -> right,cur_id * 2 + 2});
    }
    ans = max(ans, rightMost - leftMost + 1);
  }
  return ans;
}



int main(){
  return 0;
}