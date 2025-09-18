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

    void solve(TreeNode* &root, TreeNode* &prev, TreeNode* &first, TreeNode* &mid, TreeNode* &last) {
        if(!root) return;

        solve(root->left, prev, first, mid, last);

        if(prev && prev->val > root->val) {
            if(!first) {
                first = prev;
                mid = root;
            }
            else last = root;
        }
        prev = root;

        solve(root->right, prev, first, mid, last);
    }

    void recoverTree(TreeNode* root) {
        TreeNode* prev = 0;
        TreeNode* first = 0;
        TreeNode* mid = 0;
        TreeNode* last = 0;

        solve(root, prev, first, mid, last);

        if(first && last) swap(first->val, last->val);  // 2 violation  [non-adjacent nodes]
        else swap(first->val, mid->val); // 1 violation [adjacent nodes]
    }
};