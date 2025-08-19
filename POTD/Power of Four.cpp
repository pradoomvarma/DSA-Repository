class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return 0;

        // // Approach 1
        // while(n % 4 == 0) {
        //     n /= 4;
        // }

        // return n == 1;

        // // Approach 2
        // int x = (log(n) / log(4));
        // return pow(4, x) == n;

        // Approach 3   [power of 2 && n - 1 divisible by 3]
        if(((n & (n - 1)) == 0) && ((n - 1) % 3 == 0)) return 1;
        return 0;
    }
};