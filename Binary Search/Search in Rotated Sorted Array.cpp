// Solution 1

class Solution {
public:

    int findPivot(vector<int>& nums) {
        int n = nums.size();
        int st = 0, end = n - 1;

        while(st <= end) {
            int mid = st + (end - st) / 2;
            if(mid + 1 < n && nums[mid] > nums[mid + 1]) return mid;
            if(mid - 1 >= 0 && nums[mid] < nums[mid - 1]) return mid - 1;
            if(nums[mid] < nums[0]) end = mid - 1;
            else st = mid + 1;
        }

        return -1;
    }

    int bs(vector<int>& nums, int st, int end, int target) {
        while(st <= end) {
            int mid = st + (end - st) / 2;
            if(nums[mid] == target) return mid;
            else if(target < nums[mid]) end = mid - 1;
            else st = mid + 1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPivot(nums);
        if(pivot == -1) return bs(nums, 0, n - 1, target);
        else if(target >= nums[0] && target <= nums[pivot]) return bs(nums, 0, pivot, target);
        else if(pivot + 1 < n && target >= nums[pivot + 1] && target <= nums[n - 1]) {
            return bs(nums, pivot + 1, n, target);
        }
        return -1;
    }
};

// Solution 2
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0, end = n - 1;

        while(st <= end) {
            int mid = st + (end - st) / 2;
            if(nums[mid] == target) return mid;

            // left sorted
            if(nums[st] <= nums[mid]) {
                if(nums[st] <= target && target <= nums[mid]) end = mid - 1;
                else st = mid + 1;
            }
            else {
                // right sorted
                if(nums[mid] <= target && target <= nums[end]) st = mid + 1;
                else end = mid - 1;;
            }
        }

        return -1;
    }
};