// Solution 1
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    bool isValid(Node* root, int mini, int maxi) {
        if(!root) return 1;
        
        if(root->data > mini && root->data < maxi) {
            return isValid(root->left, mini, root->data) && isValid(root->right, root->data, maxi);
        }
        
        return 0;
    }
    
    int solve(Node* root) {
        if(!root) return 0;
        
        int l = solve(root->left);
        int r = solve(root->right);
        
        if(isValid(root, INT_MIN, INT_MAX)) return 1 + l + r;
        return max(l, r);
    }
    
    int largestBst(Node *root) {
        // Your code here
        return solve(root);
    }
};

// Solution 2
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class NodeVal {
    public:
    
    int mini, maxi, size;
    
    NodeVal(int mini, int maxi, int size) {
        this->mini = mini;
        this->maxi = maxi;
        this->size = size;
    }
};


class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    NodeVal solve(Node* root) {
        if(!root) return NodeVal(INT_MAX, INT_MIN, 0);
        if(!root->left && !root->right) return NodeVal(root->data, root->data, 1);
        
        auto l = solve(root->left);
        auto r = solve(root->right);
        
        if(root->data > l.maxi && root->data < r.mini) {
            return NodeVal(min(l.mini, root->data), max(root->data, r.maxi), 1 + l.size + r.size);
        }
        
        return NodeVal(INT_MIN, INT_MAX, max(l.size, r.size));
    }
    
    int largestBst(Node *root) {
        // Your code here
        return solve(root).size;
    }
};