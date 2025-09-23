class Solution {
  public:
    
    bool dfs(int src, vector<int> &vis, vector<int> &path, vector<vector<int>> &adj) {
        vis[src] = 1;
        path[src] = 1;
        
        for(auto nbr : adj[src]) {
            if(!vis[nbr]) {
                if(dfs(nbr, vis, path, adj)) return 1;
            }
            else if(path[nbr]) return 1;
        }
        
        path[src] = 0;
        return 0;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int> vis(V, 0);
        vector<int> path(V, 0);
        
        for(int i = 0; i < V; ++i) {
            if(!vis[i]) {
                if(dfs(i, vis, path, adj)) return 1;
            }
        }
        
        return 0;
    }
};

// BFS Kahn's Algorithm Topological Sort
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        
        for(auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < V; ++i) {
            if(indegree[i] == 0) q.push(i);
        }
        
        int cnt = 0;
        while(!q.empty()) {
            int node = q.front();   q.pop();
            cnt++;
            
            for(auto &nbr : adj[node]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
        
        return cnt != V;
    }
};