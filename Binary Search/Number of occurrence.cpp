class Solution {
  public:
  
    int search(vector<int>& nums, int target, bool findStartindex) {
        int ans = -1;
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (target < nums[mid]) {
                end = mid - 1;
            } else if (target > nums[mid]) {
                start = mid + 1;
            } else {
                //potential answer found
                ans = mid;
                if (findStartindex) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }

        return ans;
    }
  
    int countFreq(vector<int>& arr, int target) {
        // code here
        int stPos = search(arr, target, 1);
        int lastPos = search(arr, target, 0);
        
        if(stPos == -1 || lastPos == -1) return 0;
        
        return lastPos - stPos + 1;
    }
};
