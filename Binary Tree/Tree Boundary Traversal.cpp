/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    void leftBoundary(Node* root, vector<int> &arr) {
        if(!root) return;
        if(!root->left && !root->right) return;
        
        arr.push_back(root->data);
        if(root->left) leftBoundary(root->left, arr);
        else leftBoundary(root->right, arr);
    }
    
    void leaf(Node* root, vector<int> &arr) {
        if(!root) return;
        if(!root->left && !root->right) {
            arr.push_back(root->data);
            return;
        }
        
        leaf(root->left, arr);
        leaf(root->right, arr);
    }
    
    void rightBoundary(Node* root, vector<int> &arr) {
        if(!root) return;
        if(!root->left && !root->right) return;
        
        
        if(root->right) rightBoundary(root->right, arr);
        else rightBoundary(root->left, arr);
        arr.push_back(root->data);
    }
  
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        ans.push_back(root->data);
        if(!root->left && !root->right) return ans;
        
        leftBoundary(root->left, ans);
        leaf(root, ans);
        rightBoundary(root->right, ans);
        return ans;
    }
};