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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            auto [node, idx] = q.front();   
            q.pop();
            
            if(mp.find(idx) == mp.end()) mp[idx] = node->data;
            
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