/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void findParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent) {
        parent[root] = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            if(node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        return;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        findParent(root, parent);

        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        int d = 0;

        while(!q.empty()) {
            int n = q.size();
            vector<int> temp;

            while(n--) {
                auto node = q.front();
                q.pop();

                vis[node] = 1;
                temp.push_back(node->val);

                if(node->left && !vis[node->left]) {
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]) {
                    q.push(node->right);
                }
                if(parent[node] && !vis[parent[node]]) {
                    q.push(parent[node]);
                }
            }

            if(d == k) return temp;
            d++;
        }

        return {};
    }
};