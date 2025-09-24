// Unit weight shortest path in undirected graph -> BFS
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n = adj.size();
        vector<int> dist(n, 1e9);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        int d = 0;
        
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int node = q.front();   q.pop();
                
                for(auto nbr : adj[node]) {
                    if(d + 1 < dist[nbr]) {
                        dist[nbr] = d + 1;
                        q.push(nbr);
                    }
                }
            }
            d++;
        }
        
        for(int i = 0; i < n; ++i) {
            if(dist[i] == 1e9) dist[i] = -1;
        }
        
        return dist;
    }
};