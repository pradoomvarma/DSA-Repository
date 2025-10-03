class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        vector<vector<int>> vis(m, vector<int> (n, 0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;

        for(int i = 0; i < m; ++i) {
            pq.push({heightMap[i][0], {i, 0}});
            vis[i][0] = 1;

            pq.push({heightMap[i][n - 1], {i, n - 1}});
            vis[i][n - 1] = 1;
        }

        for(int i = 0; i < n; ++i) {
            pq.push({heightMap[0][i], {0, i}});
            vis[0][i] = 1;

            pq.push({heightMap[m - 1][i], {m - 1, i}});
            vis[m - 1][i] = 1;
        }

        int res = 0;
        int max_height = 0;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while(!pq.empty()) {
            auto t = pq.top();  pq.pop();
            int curr_height = t.first;
            int i = t.second.first;
            int j = t.second.second;

            max_height = max(max_height, curr_height);

            for(int k = 0; k < 4; ++k) {
                int x = i + dx[k];
                int y = j + dy[k];

                if(x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                    vis[x][y] = 1;
                    if(max_height - heightMap[x][y] > 0) res += max_height - heightMap[x][y];
                    pq.push({heightMap[x][y], {x, y}});
                }
            }
        }

        return res;
    }
};