class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        int st = 1, end = m;
        int ans = -1;
        
        while(st <= end) {
            long mid = st + (end - st) / 2;
            if(pow(mid, n) > m) end = mid - 1;
            else {
                ans = mid;
                st = mid + 1;
            }
        }
        
        if(pow(ans, n) != m) return -1;
        return ans;
    }
};