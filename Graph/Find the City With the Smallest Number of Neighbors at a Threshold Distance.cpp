class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int> (n, 1e8));

        for(int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }

        for(auto it : edges) {
            int i = it[0];
            int j = it[1];
            int wt = it[2];

            dist[i][j] = wt;
            dist[j][i] = wt;
        }
        
        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if (dist[i][k] == 1e8 || dist[k][j] == 1e8) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int res = 0;
        int maxi = n;
        for(int i = 0; i < n; ++i) {
            int cnt = 0;
            for(int j = 0; j < n; ++j) {
                if(dist[i][j] <= distanceThreshold) cnt++;
            }

            if(cnt <= maxi) {
                res = i;
                maxi = cnt;
            }
        }

        return res;
    }
};