// User function Template for C++
class Solution {
  public:
  
    void topoSort(int src, vector<int> &vis, stack<int> &st, vector<vector<pair<int, int>>> &adj) {
        vis[src] = 1;
        
        for(auto &nbr : adj[src]) {
            if(!vis[nbr.first]) {
                topoSort(nbr.first, vis, st, adj);
            }
        }
        
        st.push(src);
    }
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);
        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }
        
        stack<int> st;
        vector<int> vis(V, 0);
        for(int i = 0; i < V; ++i) {
            if(!vis[i]) {
                topoSort(i, vis, st, adj);
            }
        }
        
        vector<int> dist(V, 1e9);
        dist[0] = 0;
        
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            for(auto &nbr : adj[node]) {
                int adjNode = nbr.first;
                int edw = nbr.second;
                
                if(dist[node] + edw < dist[adjNode]) {
                    dist[adjNode] = dist[node] + edw;
                }
            }
        }
        
        for(int i = 0; i < V; ++i) {
            if(dist[i] == 1e9) dist[i] = -1;
        }
        
        return dist;
    }
};
