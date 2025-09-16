class Solution {
  public:
  
    void solve(Node* root, int x, int &ans) {
        if(!root) return;
        
        if(root->data >= x) {
            ans = root->data;
            solve(root->left, x, ans);
        }
        else {
            solve(root->right, x, ans);
        }
    }
  
    int findCeil(Node* root, int x) {
        // code here
        int ans = -1;
        solve(root, x, ans);
        return ans;
    }
};
