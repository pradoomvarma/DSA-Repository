class Solution {
public:
    int mySqrt(int x) {
        int st = 0, end = x;
        int ans = 0;

        while(st <= end) {
            long mid = st + (end - st) / 2;

            if(mid * mid > x) end = mid - 1;
            else {
                ans = mid;
                st = mid + 1;
            }
        }

        return ans;
    }
};