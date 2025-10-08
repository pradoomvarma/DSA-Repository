class Solution {
public:

    void dfs(int src, int par, int time, vector<int>& tin, vector<int>& low, vector<int>& vis, vector<vector<int>>& ans, vector<vector<int>> &adj) {
        vis[src] = 1;
        tin[src] = low[src] = time++;

        for(auto nbr : adj[src]) {
            if(!vis[nbr]) {
                dfs(nbr, src, time, tin, low, vis, ans, adj);
                low[src] = min(low[src], low[nbr]);
                if(tin[src] < low[nbr]) ans.push_back({src, nbr});
            }
            else if(nbr != par) {
                low[src] = min(low[src], low[nbr]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        vector<int> tin(n, 0);
        vector<int> low(n, 0);
        vector<vector<int>> ans;

        int time = 1;
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                dfs(i, -1, time, tin, low, vis, ans, adj);
            }
        }

        return ans;
    }
};