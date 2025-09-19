class Solution {
  public:
    
    void dfs(int src, vector<vector<int>>& adj, vector<int> &vis, vector<int> &ans) {
        vis[src] = 1;
        ans.push_back(src);
        
        for(auto nbr : adj[src]) {
            if(!vis[nbr]) dfs(nbr, adj, vis, ans);
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> ans;
        vector<int> vis(n, 0);
        
        dfs(0, adj, vis, ans);
        
        return ans;
    }
};