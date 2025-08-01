class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int n = nums.size();
        vector<vector<int>> ans;

        for(int i = 0; i < n - 2; ++i) {
            while(i < (n - 2) && i != 0 && nums[i] == nums[i - 1]) ++i;

            int j = i + 1, k = n - 1;
            int sum = 0 - nums[i];
            
            while(j < k) {
                if(nums[j] + nums[k] == sum) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    ++j, --k;
                    while(j < k && nums[j] == nums[j - 1]) ++j;
                    while(j < k && nums[k] == nums[k + 1]) --k;
                }
                else if(nums[j] + nums[k] < sum) ++j;
                else --k;
            }
        }

        return ans;
    }
};