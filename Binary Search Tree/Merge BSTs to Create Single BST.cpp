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

    unordered_map<int, int> roots;
    unordered_map<int, int> leafs;
    unordered_map<int, TreeNode*> mp;

    bool isValid(TreeNode* root, int mini, int maxi) {
        if(!root) return 1;

        if(root->val > mini && root->val < maxi) {
            return isValid(root->left, mini, root->val) && isValid(root->right, root->val, maxi);
        }

        return 0;
    }

    void storeLeaf(TreeNode* root) {
        if(!root) return;
        if(!root->left && !root->right) {
            leafs[root->val]++;
            return;
        }

        storeLeaf(root->left);
        storeLeaf(root->right);
    }

    void solve(TreeNode* root) {
        if(!root) return;

        if(mp.find(root->val) != mp.end()) {
            root->left = mp[root->val]->left;
            root->right = mp[root->val]->right;
            mp.erase(root->val);
        }

        solve(root->left);
        solve(root->right);
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        // if there is one tree check validity
        if(trees.size() == 1) {
            if(isValid(trees[0], INT_MIN, INT_MAX)) return trees[0];
            return 0;
        }

        // store leaf and root
        for(auto root : trees) {
            roots[root->val]++;
            storeLeaf(root);
        }

        TreeNode* root = 0;
        for(auto node : trees) {
            if(leafs.find(node->val) == leafs.end()) {
                root = node;
                break;
            }
        }

        for(auto node : trees) {
            if(node != root) {
                mp[node->val] = node;
            }
        }

        solve(root);

        if(mp.size() > 0) return 0;
        if(isValid(root, INT_MIN, INT_MAX)) return root;

        return 0;
    }   
};