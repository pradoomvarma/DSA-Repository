#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Memo tables for each direction: topLeft, topRight, bottomLeft, bottomRight
    vector<vector<vector<vector<int>>>> dp;

    int topLeft(vector<vector<int>>& grid, int i, int j, int top, int right, int prev) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return 0;

        int curr = grid[i][j];
        if ((prev == 0 && curr != 2) || (prev == 2 && curr != 0)) return 0;

        int &res = dp[0][i][j][top];
        if (res != -1) return res;

        int ans = 0;
        if (top) {
            int topVal = topLeft(grid, i - 1, j - 1, 1, 0, curr);
            int rightVal = topLeft(grid, i - 1, j + 1, 0, 1, curr);
            ans = max({ans, topVal, rightVal});
        } else {
            ans = max(ans, topLeft(grid, i - 1, j + 1, 0, 1, curr));
        }

        return res = ans + 1;
    }

    int topRight(vector<vector<int>>& grid, int i, int j, int top, int right, int prev) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return 0;

        int curr = grid[i][j];
        if ((prev == 0 && curr != 2) || (prev == 2 && curr != 0)) return 0;

        int &res = dp[1][i][j][top];
        if (res != -1) return res;

        int ans = 0;
        if (top) {
            int topVal = topRight(grid, i - 1, j + 1, 1, 0, curr);
            int rightVal = topRight(grid, i + 1, j + 1, 0, 1, curr);
            ans = max({ans, topVal, rightVal});
        } else {
            ans = max(ans, topRight(grid, i + 1, j + 1, 0, 1, curr));
        }

        return res = ans + 1;
    }

    int bottomLeft(vector<vector<int>>& grid, int i, int j, int top, int right, int prev) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return 0;

        int curr = grid[i][j];
        if ((prev == 0 && curr != 2) || (prev == 2 && curr != 0)) return 0;

        int &res = dp[2][i][j][top];
        if (res != -1) return res;

        int ans = 0;
        if (top) {
            int topVal = bottomLeft(grid, i + 1, j - 1, 1, 0, curr);
            int rightVal = bottomLeft(grid, i - 1, j - 1, 0, 1, curr);
            ans = max({ans, topVal, rightVal});
        } else {
            ans = max(ans, bottomLeft(grid, i - 1, j - 1, 0, 1, curr));
        }

        return res = ans + 1;
    }

    int bottomRight(vector<vector<int>>& grid, int i, int j, int top, int right, int prev) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return 0;

        int curr = grid[i][j];
        if ((prev == 0 && curr != 2) || (prev == 2 && curr != 0)) return 0;

        int &res = dp[3][i][j][top];
        if (res != -1) return res;

        int ans = 0;
        if (top) {
            int topVal = bottomRight(grid, i + 1, j + 1, 1, 0, curr);
            int rightVal = bottomRight(grid, i + 1, j - 1, 0, 1, curr);
            ans = max({ans, topVal, rightVal});
        } else {
            ans = max(ans, bottomRight(grid, i + 1, j - 1, 0, 1, curr));
        }

        return res = ans + 1;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (n == 1 && m == 1) return grid[0][0] == 1 ? 1 : 0;

        // dp[4][n][m][2]
        dp.assign(4, vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(2, -1))));

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    int tl = 0, tr = 0, bl = 0, br = 0;

                    if (i - 1 >= 0 && j - 1 >= 0 && grid[i - 1][j - 1] == 2)
                        tl = topLeft(grid, i - 1, j - 1, 1, 0, 1);

                    if (i - 1 >= 0 && j + 1 < m && grid[i - 1][j + 1] == 2)
                        tr = topRight(grid, i - 1, j + 1, 1, 0, 1);

                    if (i + 1 < n && j - 1 >= 0 && grid[i + 1][j - 1] == 2)
                        bl = bottomLeft(grid, i + 1, j - 1, 1, 0, 1);

                    if (i + 1 < n && j + 1 < m && grid[i + 1][j + 1] == 2)
                        br = bottomRight(grid, i + 1, j + 1, 1, 0, 1);

                    ans = max(ans, 1 + max({tl, tr, bl, br}));
                }
            }
        }

        return ans;
    }
};
