/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool solve(TreeNode* root, int &k, int &ans) {
        if(!root) return 0;

        if(solve(root->left, k, ans)) return 1;

        k--;
        if(k == 0) {
            ans = root->val;
            return 1;
        }

        if(solve(root->right, k, ans)) return 1;

        return 0;
    }

    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int ans = -1;
        solve(root, k, ans);
        return ans;
    }
};