/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    
    void inorder(Node* root, vector<int> &arr) {
        if(!root) return;
        
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
    
    vector<int> mergeArray(vector<int> bst1, vector<int> bst2) {
        int n = bst1.size();
        int m = bst2.size();
        int i = 0, j = 0, k = 0;
        vector<int> res(n + m);
        
        while(i < n && j < m) {
            if(bst1[i] < bst2[j]) {
                res[k++] = bst1[i++];
            }
            else {
                res[k++] = bst2[j++];
            }
        }
        
        while(i < n) {
            res[k++] = bst1[i++];
        }
        
        while(j < m) {
            res[k++] = bst2[j++];
        }
        
        return res;
    }
    
    
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int> bst1, bst2;
        inorder(root1, bst1);
        inorder(root2, bst2);
        
        return mergeArray(bst1, bst2);
    }
};


// construct BST from given inorder traversal
Node* buildTree(vector<int> &in, int s, int e) {
    if(s > e) return NULL;
    
    int mid = (s + e) / 2;
    Node* root = new Node(in[mid]);
    
    root->left = buildTree(in, s, mid - 1);
    root->right = buildTree(in, mid + 1, e);
    
    return root;
}