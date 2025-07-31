class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        int cnt = 0;
        mp[0] = 1;

        for(auto el : nums) {
            sum += el;
            int rem = sum - k;

            if(mp.find(rem) != mp.end()) {
                cnt += mp[rem];
            }

            mp[sum]++;
        }

        return cnt;
    }
};