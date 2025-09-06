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

    void postOrder(TreeNode* root, vector<int>& ans) {
        if(!root) return;

        postOrder(root->left, ans);
        postOrder(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOrder(root, ans);
        return ans;
    }
};

// Solution 2 : proceed in reverse of preorder fashion use 2 stacks in first push root then right and left in stack1 and 
            // in stack2 push the popped element from stack1 finally pop all elements from stack2 to ans
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;

        stack<TreeNode*> st1;
        st1.push(root);
        stack<int> st2;

        while(!st1.empty()) {
            auto node = st1.top();
            st1.pop();

            st2.push(node->val);

            if(node->left) st1.push(node->left);
            if(node->right) st1.push(node->right);
        }

        while(!st2.empty()) {
            ans.push_back(st2.top());
            st2.pop();
        }

        return ans;
    }
};

// Solution 3 : proceed in reverse of preorder fashion root->right->left and insert ans at beginning
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;

        stack<TreeNode*> st1;
        st1.push(root);

        while(!st1.empty()) {
            auto node = st1.top();
            st1.pop();

            ans.insert(ans.begin(), node->val);

            if(node->left) st1.push(node->left);
            if(node->right) st1.push(node->right);
        }

        return ans;
    }
};