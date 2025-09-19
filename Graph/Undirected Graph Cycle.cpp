class Solution {
  public:
  
    bool dfs(int src, int par, vector<int> &vis, vector<int> adj[]) {
        vis[src] = 1;
        
        for(auto nbr : adj[src]) {
            if(!vis[nbr]) {
                if(dfs(nbr, src, vis, adj)) return 1;
            }
            else if(nbr != par) return 1;
        }
        
        return 0;
    }
    
    bool bfs(int src, int par, vector<int> &vis, vector<int> adj[]) {
        queue<pair<int, int>> q;
        q.push({src, par});
        vis[src] = 1;
        
        while(!q.empty()) {
            auto [node, par] = q.front();   q.pop();
            
            for(auto nbr : adj[node]) {
                if(!vis[nbr]) {
                    vis[nbr] = 1;
                    q.push({nbr, node});
                }
                else if(nbr != par) return 1;
            }
        }
        
        return 0;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // if node is already visited and its not parent then cycle is present in graph
        vector<int> adj[V];
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V, 0);
        for(int i = 0; i < V; ++i) {
            if(!vis[i]) {
                // if(dfs(i, -1, vis, adj)) return 1;
                if(bfs(i, -1, vis, adj)) return 1;
            }
        }
        
        return 0;
    }
};