class Solution {
  public:
  
    int solve(vector<int>& arr, int target) {
        // code here
        int ans = arr.size();
        
        int st = 0, end = arr.size() - 1;
        while(st <= end) {
            int mid = st + (end - st) / 2;
            
            if(arr[mid] <= target) {
                ans = mid;
                st = mid + 1;
            }
            else end = mid - 1;
        }
        
        return ans;
    }
  
    int findFloor(vector<int>& arr, int x) {
        // code here
        int ans = solve(arr, x);
        if(ans == arr.size()) return -1;
        return ans;
    }
};
