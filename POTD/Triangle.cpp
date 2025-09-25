class Solution {
public:

    int solve(int row, int col, vector<vector<int>>& triangle, vector<vector<int>> &dp) {
        if(row == triangle.size() - 1) return triangle[row][col];

        if(dp[row][col] != -1e9) return dp[row][col];

        int ans = triangle[row][col];
        int val1 = solve(row + 1, col, triangle, dp);
        int val2 = solve(row + 1, col + 1, triangle, dp);

        return dp[row][col] = ans + min(val1, val2);
    }

    int tab(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(2, vector<int> (n, -1e9));

        for(int i = 0; i < n; ++i) dp[1][i] = triangle[n - 1][i];

        for(int row = n - 2; row >= 0; --row) {
            for(int col = row; col >= 0; --col) {
                int ans = triangle[row][col];
                int val1 = dp[1][col];
                int val2 = dp[1][col + 1];

                dp[0][col] = ans + min(val1, val2);
            }
            dp[1] = dp[0];
        }

        return dp[1][0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        // int n = triangle.size();
        // vector<vector<int>> dp(n, vector<int> (n, -1e9));

        // return solve(0, 0, triangle, dp);

        return tab(triangle);
    }
};