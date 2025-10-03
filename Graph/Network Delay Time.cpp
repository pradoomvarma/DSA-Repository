class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto it : times) {
            int u = it[0];
            int v = it[1];
            int t = it[2];

            adj[u].push_back({v, t});
        }

        vector<int> dist(n + 1, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, k});
        dist[k] = 0;
        dist[0] = 0;

        while(!pq.empty()) {
            auto [curr, node] = pq.top();   pq.pop();

            for(auto nbr : adj[node]) {
                int adjNode = nbr.first;
                int t = nbr.second;

                if(curr + t < dist[adjNode]) {
                    dist[adjNode] = curr + t;
                    pq.push({curr + t, adjNode});
                }
            }
        }

        int res = *max_element(begin(dist), end(dist));
        if(res == 1e9) return -1;
        return res;
    }
};