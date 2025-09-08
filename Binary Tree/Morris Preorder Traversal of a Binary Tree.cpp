// Solution 1
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;

        TreeNode* curr = root;

        while(curr) {
            if(!curr->left) {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr) prev = prev->right;
                if(!prev->right) {
                    prev->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                }
                else {
                    prev->right = 0;
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};

// Solution 2
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;

        TreeNode* curr = root;

        while(curr) {
            if(!curr->left) {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode* prev = curr->left;
                while(prev->right) prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = 0;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }

        return ans;
    }
};