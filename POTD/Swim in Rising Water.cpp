class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
        vector<vector<int>> vis(n, vector<int> (n, 0));

        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;

        int maxTime = 0;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while(!pq.empty()) {
            auto t = pq.top();  pq.pop();

            int currTime = t.first;
            int i = t.second.first;
            int j = t.second.second;

            maxTime = max(maxTime, currTime);
            if(i == n - 1 && j == n - 1) return maxTime;

            for(int k = 0; k < 4; ++k) {
                int x = i + dx[k];
                int y = j + dy[k];

                if(x >= 0 && x < n && y >= 0 && y < n && !vis[x][y]) {
                    vis[x][y] = 1;
                    pq.push({grid[x][y], {x, y}});
                }
            }
        }

        return maxTime;
    }
};