// Solution 1
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        nums.insert(nums.begin(), INT_MIN);
        nums.push_back(INT_MIN);
        int n = nums.size();
        int st = 1, end = n - 2;

        while(st < end) {
            int mid = st + (end - st) / 2;

            if(mid - 1 >= 0 && nums[mid - 1] <= nums[mid] && mid + 1 < n && nums[mid] > nums[mid + 1])
                return mid - 1;
            else if(mid - 1 >= 0 && nums[mid - 1] <= nums[mid] && mid + 1 < n && nums[mid] < nums[mid + 1]) {
                st = mid + 1;
            }
            else end = mid;
        }

        return st - 1;
    }
};

// Solution 2
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int st = 0, end = n - 1;

        while(st < end) {
            int mid = st + (end - st) / 2;

            if(nums[mid] > nums[mid + 1]) {
                end = mid;
            }
            else st = mid + 1;
        }

        return st;
    }
};