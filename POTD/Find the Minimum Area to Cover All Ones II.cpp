class Solution {
public:

    int minimumArea(vector<vector<int>>& grid, int stRow, int endRow, int stCol, int endCol) {
        int n = grid.size();
        int m = grid[0].size();
        int minRow = n, minCol = m;
        int maxRow = -1, maxCol = -1;

        for(int i = stRow; i < endRow; ++i) {
            for(int j = stCol; j < endCol; ++j) {
                if(grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);

                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }

        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }

    int solve(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = INT_MAX;

        // case-1 & case-2
        for(int rs = 1; rs < n; ++rs) {
            for(int cs = 1; cs < m; ++cs) {
                // case-1
                int top = minimumArea(grid, 0, rs, 0, m);
                int bottomLeft = minimumArea(grid, rs, n, 0, cs);
                int bottomRight = minimumArea(grid, rs, n, cs, m);
                ans = min(ans, top + bottomLeft + bottomRight);

                // case-2
                int topLeft = minimumArea(grid, 0, rs, 0, cs);
                int topRight = minimumArea(grid, 0, rs, cs, m);
                int bottom = minimumArea(grid, rs, n, 0, m);
                ans = min(ans, topLeft + topRight + bottom);
            }
        }

        // case-3
        for(int rs1 = 1; rs1 < n; ++rs1) {
            for(int rs2 = 1; rs2 < n; ++rs2) {
                int top = minimumArea(grid, 0, rs1, 0, m);
                int mid = minimumArea(grid, rs1, rs2, 0, m);
                int bottom = minimumArea(grid, rs2, n, 0, m);
                ans = min(ans, top + mid + bottom);
            }
        }

        return ans;
    }

    vector<vector<int>> rotateClockwise(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> rotated(m, vector<int>(n));

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                rotated[j][n - i - 1] = grid[i][j];
            }
        }

        return rotated;
    }

    int minimumSum(vector<vector<int>>& grid) {
        int ans = solve(grid);
        vector<vector<int>> rotated = rotateClockwise(grid);
        ans = min(ans, solve(rotated));
        return ans;
    }
};