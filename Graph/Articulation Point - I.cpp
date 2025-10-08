// User function Template for C++

class Solution {
  public:
  
    void dfs(int src, int par, int time, vector<int>& tin, vector<int>& low, vector<int>& vis, vector<int> &mark, vector<int> adj[]) {
        vis[src] = 1;
        tin[src] = low[src] = time++;
        
        int child = 0;
        for(auto nbr : adj[src]) {
            if(!vis[nbr]) {
                dfs(nbr, src, time, tin, low, vis, mark, adj);
                low[src] = min(low[src], low[nbr]);
                if(tin[src] <= low[nbr] && par != -1) mark[src] = 1;
                child++;
            }
            else if(nbr != par) {
                low[src] = min(low[src], tin[nbr]);
            }
        }
        
        if(child > 1 && par == -1) mark[src] = 1;
    }
  
    vector<int> articulationPoints(int n, vector<int> adj[]) {

        vector<int> vis(n, 0);
        vector<int> tin(n, 0);
        vector<int> low(n, 0);
        vector<int> mark(n, 0);

        int time = 1;
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                dfs(i, -1, time, tin, low, vis, mark, adj);
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < n; ++i) {
            if(mark[i]) ans.push_back(i);
        }
        
        if(ans.size() == 0) return {-1};

        return ans;
    }
};