class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n - 1; ++i) {
            for(int j = n - 2; j >= i; --j) {
                nums[j + 1] = (nums[j] + nums[j + 1]) % 10;
            }
        }

        return nums[n - 1];
    }
};