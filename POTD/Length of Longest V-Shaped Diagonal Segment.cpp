#include <bits/stdc++.h>
using namespace std;

// Solution 1

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


// Solution 2
class Solution {
public:

    vector<vector<int>> dir = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int n, m;
    int dp[501][501][4][2];

    int solve(vector<vector<int>>& grid, int i, int j, int d, bool turn, int val) {
        int i_ = i + dir[d][0];
        int j_ = j + dir[d][1];

        if(i_ < 0 || j_ < 0 || i_ >= n || j_ >= m || grid[i_][j_] != val) return 0;

        if(dp[i][j][d][turn] != -1) return dp[i][j][d][turn];

        int ans = 0;
        int top = 1 + solve(grid, i_, j_, d, turn, val == 2 ? 0 : 2);
        ans = max(ans, top);
        if(turn == 0) {
            int right = 1 + solve(grid, i_, j_, (d + 1) % 4, 1, val == 2 ? 0 : 2);
            ans = max(ans, right);
        }

        return dp[i][j][d][turn] = ans;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 1) {
                    for(int d = 0; d < 4; ++d) {
                        ans = max(ans, 1 + solve(grid, i, j, d, 0, 2));
                    }
                }
            }
        }

        return ans;
    }
};