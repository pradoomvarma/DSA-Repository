class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void dfs1(int node, vector<int>& vis, stack<int>& st, vector<vector<int>>& adj) {
	    vis[node] = 1;
	    
	    for(auto nbr : adj[node]) {
	        if(!vis[nbr]) dfs1(nbr, vis, st, adj);
	    }
	    
	    st.push(node);
	}
	
	void dfs2(int node, vector<int>& vis, vector<vector<int>>& adj) {
	    vis[node] = 1;
	    
	    for(auto nbr : adj[node]) {
	        if(!vis[nbr]) dfs2(nbr, vis, adj);
	    }
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int> st;
        vector<int> vis1(V, 0);
        
        for(int i = 0; i < V; ++i) {
            if(!vis1[i]) dfs1(i, vis1, st, adj);
        }
        
        vector<vector<int>> adjList(V);
        for(int i = 0; i < V; ++i) {
            for(auto nbr : adj[i]) {
                adjList[nbr].push_back(i);
            }
        }
        
        vector<int> vis2(V, 0);
        int ans = 0;
        
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(!vis2[node]) {
                dfs2(node, vis2, adjList);
                ans++;
            }
        }
        
        return ans;
    }
};
