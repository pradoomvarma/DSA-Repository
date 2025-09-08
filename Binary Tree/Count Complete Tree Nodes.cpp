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

    int maxDepth(TreeNode* node, bool left) {
        int h = 0;
        while(node) {
            h++;
            if(left) node = node->left;
            else node = node->right;
        }
        return h;
    } 

    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int lh = maxDepth(root, 1);
        int rh = maxDepth(root, 0);
        
        if(lh == rh) return pow(2, lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};