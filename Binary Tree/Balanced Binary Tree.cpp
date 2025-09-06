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

    int maxDepth(TreeNode* root, bool &ans) {
        if(!root) return 0;

        int lh = maxDepth(root->left, ans);
        int rh = maxDepth(root->right, ans);
        if(ans && abs(lh - rh) > 1) {
            ans = 0;
        }

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        bool ans = 1;
        maxDepth(root, ans);
        return ans;
    }
};