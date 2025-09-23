class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);

        for(int i = 0; i < n; ++i) {
            for(auto &nbr : graph[i]) {
                adj[nbr].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; ++i) {
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int node = q.front();   q.pop();
            
            for(auto &nbr : adj[node]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; ++i) {
            if(indegree[i] == 0) ans.push_back(i);
        }
        
        return ans;
    }
};