class Solution {
public:

    const int mod = 1e9 + 7;
    // int dp[1001];

    // int solve(int days, int delay, int forget) {
    //     if(days == 1) return 1;

    //     if(dp[days] != -1) return dp[days];

    //     int res = 0;
    //     for(int d = days - forget + 1; d <= days - delay; ++d) {
    //         if(d > 0) res = (res + solve(d, delay, forget)) % mod;
    //     }

    //     return dp[days] = res;
    // }

    int bottomUp(int n, int delay, int forget) {
        int total = 0;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;

        for(int days = 2; days <= n; ++days) {
            int res = 0;
            for(int d = days - forget + 1; d <= days - delay; ++d) {
                if(d > 0) res = (res + dp[d]) % mod;
            }

            dp[days] = res;
        }

        for(int days = n - forget + 1; days <= n; ++days) {
            if(days > 0) total = (total + dp[days]) % mod;
        }

        return total;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        // int total = 0;
        // memset(dp, -1, sizeof(dp));

        // for(int days = n - forget + 1; days <= n; ++days) {
        //     if(days > 0) total = (total + solve(days, delay, forget)) % mod;
        // }

        // return total;

        return bottomUp(n, delay, forget);
    }
};