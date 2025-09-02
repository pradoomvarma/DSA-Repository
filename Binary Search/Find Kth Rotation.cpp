class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int st = 0, end = n - 1;
        int ans = -1;
        int mini = INT_MAX;
        
        while(st <= end) {
            int mid = st + (end - st) / 2;
            
            if(arr[st] <= arr[mid]) {
                // left part sorted
                if(arr[st] < mini) {
                    mini = arr[st];
                    ans = st;
                }
                st = mid + 1;
            }
            else {  // right part sorted
                if(arr[mid] < mini) {
                    mini = arr[mid];
                    ans = mid;
                }
                end = mid - 1;
            }
        }
        
        return ans;
    }
};
