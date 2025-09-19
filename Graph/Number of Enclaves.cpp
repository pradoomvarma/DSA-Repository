class Solution {
public:

    int n, m;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<int>>& grid) {
        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0 || vis[x][y]) return;

        vis[x][y] = 1;
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            dfs(nx, ny, vis, grid);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> vis(m, vector<int> (n, 0));

        for(int i = 0; i < n; ++i) {
            if(grid[0][i] == 1) dfs(0, i, vis, grid);
            if(grid[m - 1][i] == 1) dfs(m - 1, i, vis, grid);
        }

        for(int i = 0; i < m; ++i) {
            if(grid[i][0] == 1) dfs(i, 0, vis, grid);
            if(grid[i][n - 1] == 1) dfs(i, n - 1, vis, grid);
        }

        int cnt = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1 && !vis[i][j]) cnt++;
            }
        }

        return cnt;
    }
};