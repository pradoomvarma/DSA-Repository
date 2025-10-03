class Solution {
public:

    typedef long long ll;
    const int mod = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll, ll>>> adj(n);
        for(auto it : roads) {
            int u = it[0];
            int v = it[1];
            int t = it[2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        } 

        vector<ll> dist(n, 1e18);
        vector<ll> path(n, 0);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>> > pq;

        pq.push({0, 0});
        dist[0] = 0;
        path[0] = 1;

        while(!pq.empty()) {
            auto [time, node] = pq.top();   pq.pop();

            for(auto nbr : adj[node]) {
                ll adjNode = nbr.first;
                ll t = nbr.second;

                if(time + t < dist[adjNode]) {
                    dist[adjNode] = time + t;
                    pq.push({time + t, adjNode});
                    path[adjNode] = path[node] % mod;
                }
                else if(time + t == dist[adjNode]) {
                    path[adjNode] = (path[adjNode] + path[node]) % mod;
                }
            }
        }

        return path[n - 1];
    }
};