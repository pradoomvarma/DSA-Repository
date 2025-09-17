// Solution 1
class Solution {
public:

    bool solve(TreeNode* root, int k, unordered_map<int, int> &mp) {
        if(!root) return 0;

        int req = k - root->val;
        if(mp.find(req) != mp.end()) return 1;
        mp[root->val]++;

        return solve(root->left, k, mp) || solve(root->right, k, mp);
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> mp;
        return solve(root, k, mp);
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

class BSTIterator {
public:

    stack<TreeNode*> st1;
    stack<TreeNode*> st2;

    void left(TreeNode* root) {
        while(root) {
            st1.push(root);
            root = root->left;
        }
    }

    void right(TreeNode* root) {
        while(root) {
            st2.push(root);
            root = root->right;
        }
    }

    BSTIterator(TreeNode* root, bool f) {
        if(f) left(root);
        else right(root);
    }
    
    int next() {
        auto node = st1.top();   st1.pop();
        left(node->right);
        return node->val;
    }

    int prev() {
        auto node = st2.top();   st2.pop();
        right(node->left);
        return node->val;
    }
    
    bool hasNext() {
        return !st1.empty();
    }

    bool hasprev() {
        return !st2.empty();
    }
};

class Solution {
public:

    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root, 1);
        BSTIterator r(root, 0);

        int i = l.next();
        int j = r.prev();

        while(i != j) {
            if(i + j == k) return 1;
            else if(i + j < k) i = l.next();
            else j = r.prev();
        }

        return 0;
    }
};