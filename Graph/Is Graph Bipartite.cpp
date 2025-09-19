class Solution {
public:

    bool dfs(int src, int col, vector<int> &color, vector<vector<int>>& adj) {
        color[src] = col;

        for(auto nbr : adj[src]) {
            if(color[nbr] == -1) {
                if(dfs(nbr, 1 - col, color, adj) == 0) return 0;
            }
            else if(col == color[nbr]) return 0;
        }

        return 1;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i = 0; i < n; ++i) {
            if(color[i] == -1) {
                if(dfs(i, 1, color, graph) == 0) return 0;
            }
        }

        return 1;
    }
};