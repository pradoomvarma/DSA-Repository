class Solution {
public:

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<int>> &vis) {
        vis[i][j] = 1;

        int m = heights.size();
        int n = heights[0].size();

        for(int k = 0; k < 4; ++k) {
            int x = i + dx[k];
            int y = j + dy[k];

            if(x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && heights[x][y] >= heights[i][j]) {
                dfs(x, y, heights, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> p(m, vector<int> (n, 0));
        vector<vector<int>> a(m, vector<int> (n, 0));

        for(int i = 0; i < n; ++i) {
            if(!p[0][i]) {
                dfs(0, i, heights, p);
            }
        }
        for(int i = 0; i < m; ++i) {
            if(!p[i][0]) {
                dfs(i, 0, heights, p);
            }
        }

        for(int i = 0; i < n; ++i) {
            if(!a[m - 1][i]) {
                dfs(m - 1, i, heights, a);
            }
        }
        for(int i = 0; i < m; ++i) {
            if(!a[i][n - 1]) {
                dfs(i, n - 1, heights, a);
            }
        }

        vector<vector<int>> res;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(a[i][j] && p[i][j]) res.push_back({i, j});
            }
        }

        return res;
    }
};