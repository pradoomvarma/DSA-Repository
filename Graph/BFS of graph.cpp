class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n = adj.size();
        vector<int> ans;
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty()) {
            int src = q.front();    q.pop();
            ans.push_back(src);
            
            for(auto nbr : adj[src]) {
                if(!vis[nbr]) {
                    vis[nbr] = 1;
                    q.push(nbr);
                }
            }
        }
        
        return ans;
    }
};