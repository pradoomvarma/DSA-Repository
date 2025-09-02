// Solution 1
class Solution {
public:

    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int st = 0, end = n - 1;

        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
                if(mid % 2 == 0) {
                    // right side
                    end = mid - 1;
                }
                else {
                    // left side
                    st = mid + 1;
                } 
            }
            else if(mid + 1 < n && nums[mid] == nums[mid + 1]) {
                if(mid % 2 == 0) {
                    // left side
                    st = mid + 1;
                }
                else {
                    // right side
                    end = mid - 1;
                } 
            }
            else return nums[mid];
        }
        
        return -1;
    }
};

// Solution 2
class Solution {
public:
    // Single element will always present on even position
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int st = 0, end = n - 1;

        while(st < end) {
            int mid = st + (end - st) / 2;
            if(mid % 2 == 1) mid--;

            if(nums[mid] != nums[mid + 1]) {
                // right side or possible ans
                end = mid;
            }
            else {
                // left side
                st = mid + 2;   // bcoz mid == mid + 1
            }
        }
        
        return nums[st];
    }
};