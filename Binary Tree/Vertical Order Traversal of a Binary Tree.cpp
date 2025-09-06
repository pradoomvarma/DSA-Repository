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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;

        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            auto node = f.first;
            int i = f.second.first;
            int j = f.second.second;
            mp[j].push_back({node->val, i});

            if(node->left) q.push({node->left, {i + 1, j - 1}});
            if(node->right) q.push({node->right, {i + 1, j + 1}});
        }

        vector<vector<int>> ans;
        for(auto it : mp) {
            auto vec = it.second;
            sort(begin(vec), end(vec), [&](pair<int, int> &a, pair<int, int> &b) {
                if(a.second == b.second) return a.first < b.first;
                return a.second < b.second;
            });
            vector<int> temp;
            for(auto el : vec) {
                temp.push_back(el.first);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};