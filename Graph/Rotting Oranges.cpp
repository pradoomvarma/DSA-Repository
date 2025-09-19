class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        queue<pair<int, int>> q;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 2) q.push({i, j});
            }
        }

        int time = 0;
        while(!q.empty()) {
            int sz = q.size();
            bool f = 0;
            while(sz--) {
                auto [i, j] = q.front();    q.pop();
                for(int k = 0; k < 4; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        if(f == 0) f = 1;
                        q.push({x, y});
                    }
                }
            }
            if(f) time++;
        }

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) return -1;
            }
        }

        return time;
    }
};