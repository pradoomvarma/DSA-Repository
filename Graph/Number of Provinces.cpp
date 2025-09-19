class Solution {
public:

    void dfs(int src, vector<vector<int>> adj, vector<int> &vis) {
        vis[src] = 1;
        
        for(auto nbr : adj[src]) {
            if(!vis[nbr]) dfs(nbr, adj, vis);
        }
    }
    
    void bfs(int src, vector<vector<int>> adj, vector<int> &vis) {
        queue<int> q;
        q.push(src);
        vis[src] = 1;
        
        while(!q.empty()) {
            int node = q.front();   q.pop();
            
            for(auto nbr : adj[node]) {
                if(!vis[nbr]) {
                    vis[nbr] = 1;
                    q.push(nbr);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n + 1);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(isConnected[i][j]) {
                    adj[i].push_back(j);
                }
            }
        }
        
        int cnt = 0;
        vector<int> vis(n, 0);
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                cnt++;
                // dfs(i, adj, vis);
                bfs(i, adj, vis);
            }
        }
        
        return cnt;
    }
};