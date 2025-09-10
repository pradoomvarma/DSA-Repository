// Solution 1
class Solution {
public:

    int solve(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        int i = 0;
        int ans = 0;

        for(int j = 0; j < n; ++j) {
            if(nums[j] & 1) cnt++;

            while(cnt > k) {
                if(nums[i] & 1) cnt--;
                ++i;
            }

            ans += (j - i + 1);
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};

// Solution 2
class Solution {
public:

    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int cnt = 0;

        for(auto el : nums) {
            sum += (el & 1);
            int req = sum - k;
            if(mp.find(req) != mp.end()) cnt += mp[req];
            mp[sum]++;
        }

        return cnt;
    }
};