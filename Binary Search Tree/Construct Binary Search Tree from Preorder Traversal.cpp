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

    TreeNode* solve(vector<int>& preorder, int &i, int ub) {
        TreeNode* root = 0;
        if(i >= preorder.size()) return root;

        int val = preorder[i];
        if(val < ub) {
            root = new TreeNode(val);
            ++i;
            root->left = solve(preorder, i, val);
            root->right = solve(preorder, i, ub);
        }

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return solve(preorder, i, INT_MAX);
    }
};