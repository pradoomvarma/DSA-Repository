/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            auto [node, idx] = q.front();   
            q.pop();
            
            mp[idx] = node->data;
            
            if(node->left) q.push({node->left, idx - 1});
            if(node->right) q.push({node->right, idx + 1});
        }
        
        vector<int> ans;
        for(auto it : mp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};