// User function template for C++
class Solution {
  public:
  
    int lowerBound(vector<int>& arr, int m, int val) {
        int st = 0, end = m - 1;
        int ans = m;
        
        while(st <= end) {
            int mid = st + (end - st) / 2;
            
            if(arr[mid] >= val) {
                ans = mid;
                end = mid - 1;
            }
            else st = mid + 1;
        }
        
        return ans;
    }
  
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        
        // we cannot optimize row traversal but every row is sorted so we can apply bs on row to find count of 1's
        int maxCnt = 0;
        int idx = -1;
        for(int i = 0; i < n; ++i) {
            int cnt = m - lowerBound(arr[i], m, 1);
            if(cnt > maxCnt) {
                idx = i;
                maxCnt = cnt;
            }
        }
        
        return idx;
    }
};