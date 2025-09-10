// Solution 1
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int cnt = 0;

        for(auto el : nums) {
            sum += el;
            int req = sum - goal;
            if(mp.find(req) != mp.end()) cnt += mp[req];
            mp[sum]++;
        }

        return cnt;
    }
};

// Solution 2
class Solution {
public:

    int solve(vector<int>& nums, int k) {
        if(k < 0) return 0;

        int n = nums.size();
        int l = 0, r = 0, cnt = 0, sum = 0;

        while(r < n) {
            sum += nums[r];

            while(sum > k) {
                sum -= nums[l];
                ++l;
            }

            cnt += (r - l + 1);
            ++r;
        }

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal - 1);
    }
};