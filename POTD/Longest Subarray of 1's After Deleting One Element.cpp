class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt0 = 0;
        int ans = 0;
        int i = 0;
        for(int j = 0; j < nums.size(); ++j) {
            if(nums[j] == 0) cnt0++;

            while(cnt0 > 1) {
                if(nums[i] == 0) cnt0--;
                ++i;
            }

            ans = max(ans, j - i);
        }

        return ans;
    }
};