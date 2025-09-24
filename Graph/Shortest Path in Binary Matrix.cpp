class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1) return -1;

        vector<vector<int>> dist(n, vector<int> (n, 1e9));
        queue<pair<int, pair<int, int>>> pq;

        pq.push({1, {0, 0}});
        dist[0][0] = 1;

        while(!pq.empty()) {
            auto cell = pq.front();    pq.pop();
            int len = cell.first;
            int x = cell.second.first;
            int y = cell.second.second;

            for(int i = -1; i <= 1; ++i) {
                for(int j = -1; j <= 1; ++j) {
                    int nx = x + i;
                    int ny = y + j;

                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && len + 1 < dist[nx][ny]) {
                        dist[nx][ny] = len + 1;
                        pq.push({len + 1, {nx, ny}});
                    }
                }
            }
        }

        if(dist[n - 1][n - 1] == 1e9) return -1;
        return dist[n - 1][n - 1];
    }
};