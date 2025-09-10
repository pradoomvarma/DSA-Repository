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

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int ins, int ine, 
                    unordered_map<int, int> &mp) {
        if(ps > pe || ins > ine) return 0;

        int val = preorder[ps];
        TreeNode* root = new TreeNode(val);
        
        int idx = mp[val];
        int numOfElem = idx - ins;

        root->left = solve(preorder, inorder, ps + 1, ps + numOfElem, ins, idx - 1, mp);
        root->right = solve(preorder, inorder, ps + numOfElem + 1, pe, idx + 1, ine, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int, int> mp;     // map index of elem of inorder
        for(int i = 0; i < n; ++i) mp[inorder[i]] = i;

        return solve(preorder, inorder, 0, n - 1, 0, n - 1, mp);
    }
};