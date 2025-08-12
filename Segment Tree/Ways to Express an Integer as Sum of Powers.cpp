class Solution {
public:
    int mod = 1e9+7;
    int dp[301][301];

    int solve(int n, int x, int num) {
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(pow(num, x) > n) return 0;

        if(dp[n][num] != -1) return dp[n][num];

        int power = pow(num, x);
        int inc = solve(n - power, x, num + 1) % mod;
        int exc = solve(n, x, num + 1) % mod;

        return dp[n][num] = (inc + exc) % mod;
    }

    int numberOfWays(int n, int x) {
        memset(dp, -1, sizeof(dp));
        return solve(n, x, 1);
    }
};