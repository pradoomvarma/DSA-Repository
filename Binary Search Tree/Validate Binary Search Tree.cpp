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

    int solve(TreeNode* root, bool left) {
        TreeNode* curr = root;
        int ans;
        while(curr) {
            ans = curr->val;
            if(!left) curr = curr->left;
            else curr = curr->right;
        }
        return ans;
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return 1;
        if(!root->left && !root->right) return 1;

        long long l = root->left ? solve(root->left, 1) : LLONG_MIN;
        long long r = root->right ? solve(root->right, 0) : LLONG_MAX;

        return l < root->val && r > root->val && isValidBST(root->left) && isValidBST(root->right);
    }
};

// Solution 2
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

    bool solve(TreeNode* root, long mini, long maxi) {
        if(!root) return 1;

        if(root->val > mini && root->val < maxi) {
            return solve(root->left, mini, root->val) && solve(root->right, root->val, maxi);
        }

        return 0;
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return 1;
        if(!root->left && !root->right) return 1;

        return solve(root, LONG_MIN, LONG_MAX);
    }
};