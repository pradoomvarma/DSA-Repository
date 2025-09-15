class Solution {
public:

    int solve(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int i = 0;
        int sum = 0;

        for(int j = 0; j < n; ++j) {
            mp[nums[j]]++;

            while(mp.size() > k) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                ++i;
            }

            sum += (j - i + 1);
        }

        return sum;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};