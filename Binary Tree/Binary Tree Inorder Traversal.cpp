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

    void inOrder(TreeNode* root, vector<int>& ans) {
        if(!root) return;

        inOrder(root->left, ans);
        ans.push_back(root->val);
        inOrder(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inOrder(root, ans);
        return ans;
    }
};

// Solution 2
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(1) {
            if(curr) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                if(st.empty()) break;
                curr = st.top();    st.pop();
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }

        return ans;
    }
};