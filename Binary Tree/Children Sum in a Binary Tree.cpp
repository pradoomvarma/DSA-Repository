/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
  
    int solve(Node* root, int &ans) {
        if(!root) return 0;
        if(!root->left && !root->right) return root->data;
        
        int l = solve(root->left, ans);
        int r = solve(root->right, ans);
        
        if(ans && (l + r != root->data)) ans = 0;
        
        return root->data;
    }
  
    int isSumProperty(Node *root) {
        // code here
        int ans = 1;
        solve(root, ans);
        return ans;
    }
};