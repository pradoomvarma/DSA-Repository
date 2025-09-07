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

    void solve(TreeNode* root, string str, vector<string>& ans) {
        if(!root) return;
        if(!root->left && !root->right) {
            str += to_string(root->val);
            ans.push_back(str);
        }

        str += to_string(root->val) + "->";
        solve(root->left, str, ans);
        solve(root->right, str, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;
        string str = "";
        solve(root, str, ans);
        return ans;
    }
};