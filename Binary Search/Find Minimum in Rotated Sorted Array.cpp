// Solution 1

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int st = 0, end = n - 1;

        while(st <= end) {
            int mid = st + (end - st) / 2;
            if(mid + 1 < n && nums[mid] > nums[mid + 1]) return nums[mid + 1];
            if(mid - 1 >= 0 && nums[mid] < nums[mid - 1]) return nums[mid];
            if(nums[mid] < nums[0]) end = mid - 1;
            else st = mid + 1;
        }

        return nums[0];
    }
};

// Solution 2
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int st = 0, end = n - 1;
        int ans = INT_MAX;

        while(st <= end) {
            int mid = st + (end - st) / 2;
            
            if(nums[st] <= nums[mid]) {
                // left sorted
                ans = min(ans, nums[st]);
                st = mid + 1;
            }
            else {
                // right sorted
                ans = min(ans, nums[mid]);
                end = mid - 1;
            }
        }

        return ans;
    }
};