class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));

        int n = nums.size();
        vector<vector<int>> ans;

        for(int i = 0; i < n - 3; ++i) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            for(int l = i + 1; l < n - 2; ++l) {
                if(l > (i + 1) && nums[l] == nums[l - 1]) continue;

                int j = l + 1, k = n - 1;
                long sum = target - (long)(nums[i] + nums[l]);
                
                while(j < k) {
                    if(nums[j] + nums[k] == sum) {
                        ans.push_back({nums[i], nums[l], nums[j], nums[k]});
                        ++j, --k;
                        while(j < k && nums[j] == nums[j - 1]) ++j;
                        while(j < k && nums[k] == nums[k + 1]) --k;
                    }
                    else if(nums[j] + nums[k] < sum) ++j;
                    else --k;
                }
            }
        }

        return ans;
    }
};