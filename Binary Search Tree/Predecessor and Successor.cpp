/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
  
    void solve(Node* root, int key,  Node* &pred,  Node* &succ) {
        if(!root) return;
        
        solve(root->left, key, pred, succ);
        
        if(root->data < key) pred = root;
        else if(!succ && root->data > key) succ = root;
        
        solve(root->right, key, pred, succ);
    }
  
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* pred = 0;
        Node* succ = 0;
        solve(root, key, pred, succ);
        return {pred, succ};
    }
};