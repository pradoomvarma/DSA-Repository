/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:

        void solve(TreeNode* root, vector<int>& preorder, vector<int>& inorder, vector<int>& postorder) {
            if(!root) return;
            
            preorder.push_back(root->data);
            solve(root->left, preorder, inorder, postorder);
            inorder.push_back(root->data);
            solve(root->right, preorder, inorder, postorder);
            postorder.push_back(root->data);
        }

		vector<vector<int> > treeTraversal(TreeNode* root){
			//your code goes here
            vector<int> inorder;
            vector<int> preorder;
            vector<int> postorder;

            solve(root, preorder, inorder, postorder);

            return {inorder, preorder, postorder};
		}
};