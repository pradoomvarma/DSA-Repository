class Solution {
  public:
  
    int upper_bound(vector<int>& arr, int x) {
        int m = arr.size();
        int st = 0, end = m - 1;
        int ans = m;
        
        while(st <= end) {
            int mid = st + (end - st) / 2;
            if(arr[mid] > x) {
                ans = mid;
                end = mid - 1;
            }
            else st = mid + 1;
        }
        
        return ans;
    }
  
    int solve(vector<vector<int>> &mat, int x) {
        int cnt = 0;
        for(int i = 0; i < mat.size(); ++i) {
            cnt += upper_bound(mat[i], x);
        }
        return cnt;
    }
  
    int median(vector<vector<int>> &mat) {
        // code here
        // BS + BB  TC = O(log(maxVal) + n * log(m))
        int n = mat.size();
        int m = mat[0].size();
        int req = (n * m) / 2;      // we want to find 1st elem which have greater than num of elem less than equal to (n + m) / 2
        
        int l = INT_MAX;
        int h = INT_MIN;
        for(int i = 0; i < n; ++i) {
            l = min(l, mat[i][0]);
            h = max(h, mat[i][m - 1]);
        }
        
        while(l <= h) {
            int mid = l + (h - l) / 2;
            int smallEqual = solve(mat, mid);   // find how many elem less than or equal to mid
            if(smallEqual <= req) l = mid + 1;
            else h = mid - 1;
        }
        
        return l;   // h makes partiton so l will be median
    }
};
