class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return 0;

        int cnt = 0;
        while(n > 0) {
            cnt += (n % 3);
            n /= 3;
        }

        return cnt == 1;
    }
};