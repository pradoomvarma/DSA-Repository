class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();

        for(int k = n - 1; k >= 2; --k) {
            int i = k - 2, j = k - 1;
            while(i >= 0) {
                if(nums[i] + nums[j] > nums[k]) return (nums[i] + nums[j] + nums[k]);
                --i;
            }
        }

        return 0;
    }
};