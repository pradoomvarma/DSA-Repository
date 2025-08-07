class Solution {
public:
    int n;
    int solve2(int i, int j, vector<vector<int>>& fruits, vector<vector<int>>& dp) {
        if(i < 0 || i >= n || j < 0 || j >= n) return 0;
        if(i == n - 1 && j == n - 1) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int maxi = 0;
        if(i == j) maxi = max(maxi, solve2(i + 1, j + 1, fruits, dp));
        else if(i + 1 == j) {
            maxi = max({maxi, solve2(i + 1, j, fruits, dp), solve2(i + 1, j + 1, fruits, dp)});
        }
        else {
            maxi = max({maxi, 
                        solve2(i + 1, j, fruits, dp), 
                        solve2(i + 1, j + 1, fruits, dp),
                        solve2(i + 1, j - 1, fruits, dp)});
        }

        return dp[i][j] = fruits[i][j] + maxi;
    }

    int solve3(int i, int j, vector<vector<int>>& fruits, vector<vector<int>>& dp) {
        if(i < 0 || i >= n || j < 0 || j >= n) return 0;
        if(i == n - 1 && j == n - 1) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int maxi = 0;
        if(i == j) maxi = max(maxi, solve3(i + 1, j + 1, fruits, dp));
        else if(i - 1 == j) {
            maxi = max({maxi, solve3(i + 1, j + 1, fruits, dp), solve3(i, j + 1, fruits, dp)});
        }
        else {
            maxi = max({maxi, 
                        solve3(i, j + 1, fruits, dp), 
                        solve3(i + 1, j + 1, fruits, dp),
                        solve3(i - 1, j + 1, fruits, dp)});
        }

        return dp[i][j] = fruits[i][j] + maxi;
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        int c1 = 0;
        for(int i = 0; i < n; ++i) {
            c1 += fruits[i][i];
            fruits[i][i] = 0;
        }

        int c2 = solve2(0, n - 1, fruits, dp);
        int c3 = solve3(n - 1, 0, fruits, dp);

        return c1 + c2 + c3;
    }
};