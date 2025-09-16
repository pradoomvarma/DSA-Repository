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

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return 0;

        if(root->val == key) {
            if(!root->left) return root->right;
            else {
                TreeNode* c = root->left;
                TreeNode* p = 0;
                while(c->right) {
                    p = c;
                    c = c->right;
                }
                if(p) p->right = c->left;
                else root->left = root->left->left;
                root->val = c->val;
            }
            return root;
        }

        if(key < root->val) root->left = deleteNode(root->left, key);
        else root->right = deleteNode(root->right, key);

        return root;
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

    TreeNode* solve(TreeNode* root) {
        if(!root->left) return root->right;
        else if(!root->right) return root->left;

        TreeNode* p = root->left;
        while(p->right) p = p->right;
        p->right = root->right;
        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val == key) return solve(root);

        TreeNode* dummy = root;

        while(root) {
            if(root->val > key) {
                if(root->left && root->left->val == key) {
                    root->left = solve(root->left);
                    break;
                }
                else root = root->left;
            }
            else {
                if(root->right && root->right->val == key) {
                    root->right = solve(root->right);
                    break;
                }
                else root = root->right;
            }
        }

        return dummy;
    }
};