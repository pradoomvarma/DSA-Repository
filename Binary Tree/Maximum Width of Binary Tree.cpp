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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int ans = INT_MIN;

        while(!q.empty()) {
            int n = q.size();
            int first = 0, last = 0;
            for(int i = 0; i < n; ++i) {
                auto [node, idx] = q.front();   
                q.pop();

                if(i == 0) first = idx;
                if(i == n - 1) last = idx;

                if(node->left) q.push({node->left, (idx << 1) + 1});
                if(node->right) q.push({node->right, (idx << 1) + 2});
            }
            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};

// Solution 2
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int ans = 0;

        while(!q.empty()) {
            int n = q.size();
            long long first = 0, last = 0;
            long long mini = q.front().second;    // to prevent overflow subtract first idx value
            for(int i = 0; i < n; ++i) {
                auto node = q.front().first;
                long long idx = q.front().second - mini;   
                q.pop();

                if(i == 0) first = idx;
                if(i == n - 1) last = idx;

                if(node->left) q.push({node->left, 2 * idx + 1});    // doing (idx << 1) this will get accepted 
                if(node->right) q.push({node->right, 2 * idx + 2});
            }
            ans = max(1ll * ans, last - first + 1);
        }

        return ans;
    }
};