class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : flights) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, 1e9);

        q.push({0, {src, -1}});
        int ans = 1e9;

        while(!q.empty()) {
            auto f = q.front();  q.pop();
            int cost = f.first;
            int node = f.second.first;
            int stops = f.second.second;

            if(stops >= k) continue;

            for(auto nbr : adj[node]) {
                int adjNode = nbr.first;
                int wt = nbr.second;

                if(stops < k && cost + wt < dist[adjNode]) {
                    dist[adjNode] = cost + wt;
                    q.push({cost + wt, {adjNode, stops + 1}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};