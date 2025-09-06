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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        
        map<int, int> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            auto [node, idx] = q.front();   
            q.pop();
            
            mp[idx] = node->val;
            
            if(node->left) q.push({node->left, idx + 1});
            if(node->right) q.push({node->right, idx + 1});
        }
        
        vector<int> ans;
        for(auto it : mp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};

// Solution 2
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        int lastVal;
        
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto node = q.front();   
                q.pop();
                
                lastVal = node->val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(lastVal);
        }
        
        return ans;
    }
};