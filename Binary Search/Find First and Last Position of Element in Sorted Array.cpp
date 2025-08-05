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

    vector<int> searchRange(vector<int>& nums, int target) {
        int stPos = search(nums, target, 1);
        int lastPos = search(nums, target, 0);

        return {stPos, lastPos};
    }
};