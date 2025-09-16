// Function to search a node in BST.
class Solution {

  public:
  
    void solve(Node* root, int x, int &ans) {
        if(!root) return;
        
        if(root->data <= x) {
            ans = root->data;
            solve(root->right, x, ans);
        }
        else {
            solve(root->left, x, ans);
        }
    }
  
    int floor(Node* root, int x) {
        // Code here
        int ans = -1;
        solve(root, x, ans);
        return ans;
    }
};