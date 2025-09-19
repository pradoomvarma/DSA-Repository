
class Solution {
  public:
  
    void dfs(int src, vector<int> adj[], vector<int> &vis, vector<int> &arr) {
        vis[src] = 1;
        arr.push_back(src);
        
        for(auto nbr : adj[src]) {
            if(!vis[nbr]) dfs(nbr, adj, vis, arr);
        }
    }
    
    void bfs(int src, vector<int> adj[], vector<int> &vis, vector<int> &arr) {
        queue<int> q;
        q.push(src);
        vis[src] = 1;
        
        while(!q.empty()) {
            int node = q.front();   q.pop();
            arr.push_back(node);
            
            for(auto nbr : adj[node]) {
                if(!vis[nbr]) {
                    vis[nbr] = 1;
                    q.push(nbr);
                }
            }
        }
    }
  
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adj[V];
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<vector<int>> ans;
        vector<int> vis(V, 0);
        for(int i = 0; i < V; ++i) {
            if(!vis[i]) {
                vector<int> temp;
                // dfs(i, adj, vis, temp);
                bfs(i, adj, vis, temp);
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};
