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

    TreeNode* findParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent, int start) {
        parent[root] = 0;
        TreeNode* target = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            if(node->val == start) target = node;

            if(node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        return target;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* target = findParent(root, parent, start);

        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        int time = 0;

        while(!q.empty()) {
            int n = q.size();
            bool isInfected = 0;

            while(n--) {
                auto node = q.front();
                q.pop();
                vis[node] = 1;

                if(node->left && !vis[node->left]) {
                    isInfected = 1;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]) {
                    isInfected = 1;
                    q.push(node->right);
                }
                if(parent[node] && !vis[parent[node]]) {
                    isInfected = 1;
                    q.push(parent[node]);
                }
            }
            if(!isInfected) break;
            time++;
        }

        return time;
    }
};